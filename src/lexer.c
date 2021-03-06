//-----------------------------------------------------------------------------
//
// This source file is part of sash, the Super Awesome Shell
//
// Copyright (C) 2019, 2020 Vilson Fabricio Juliatto <vfabricio2201@gmail.com>
//
// This software is distributed under the terms of the AGPL v3.0 license.
// See the LICENSE file at the root of this project for more details.
//
//-----------------------------------------------------------------------------

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "lexer.h"
#include "utilities.h"
#include "wrappers.h"

tokens initialize_token_container()
{
    char** tokens_list = alloc(INITIAL_CAPACITY * sizeof(char*));
    tokens t = {tokens_list, 0, INITIAL_CAPACITY};
    return t;
}

tokens add_token(tokens t, char* s) {
    char** new_tokens_list = NULL;
    size_t new_n = t.n + 1;
    size_t new_capacity = t.capacity;
    if (new_n > t.capacity) {
        new_capacity *= 2;
        new_tokens_list = resize_alloc(t.tokens_list, new_capacity);
    } else {
        new_tokens_list = t.tokens_list;
    }
    if (s == NULL) {
        new_tokens_list[t.n] = NULL;
    } else {
        new_tokens_list[t.n] = s;
    }
    tokens new_t = {new_tokens_list, new_n, new_capacity};
    return new_t;
}

void free_tokens(tokens t)
{
    for(size_t i = 0; i < t.n; i++) {
        free(t.tokens_list[i]);
    }
    free(t.tokens_list);
}

tokens tokenize (const char* s) {
    tokens t = initialize_token_container();
    size_t token_start = 0;
    bool reading_token = false;
    size_t i;
    for(i = 0; s[i] != '\0'; i++) {
        if(s[i] != ' ' && !reading_token) {
            reading_token = true;
            token_start = i;
        } else if (s[i] == ' ' && reading_token) {
            reading_token = false;
            t = add_token(t, slice(s, token_start, i + 1));
        }
    }
    // Up to i, instead of i + 1, to omit the trailing newline
    t = add_token(t, slice(s, token_start, i));
    // This may look weird, but it makes easier to call execv later.
    t = add_token(t, NULL);
    return t;
}
