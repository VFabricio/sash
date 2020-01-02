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
#include <stdlib.h>
#include <string.h>
#include "builtins.h"

void builtin_exit(tokens t) {
    exit(EXIT_SUCCESS);
}

// WARNING: the three following definitions must always be kept in sync.
// BE EXTREMELY CAREFUL TO ENSURE THIS!!!

size_t number_builtins = 1;
char* builtin_names[] = {"exit"};
void (*builtins[])(tokens t) = {builtin_exit};

bool is_builtin(tokens t)
{
    for(size_t i = 0; i < number_builtins; i++) {
        if(strcmp(t.tokens_list[0], builtin_names[i]) == 0) {
            return true;
        }
    }
    return false;
}

void run_builtin(tokens t)
{
    for(size_t i = 0; i < number_builtins; i++) {
        if(strcmp(t.tokens_list[0], builtin_names[i]) == 0) {
            builtins[i](t);
        }
    }
}