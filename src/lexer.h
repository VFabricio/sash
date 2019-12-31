//-----------------------------------------------------------------------------
//
// This source file is part of sash, the Super Awesome Shell
//
// Copyright (C) 2019 Vilson Fabricio Juliatto <vfabricio2201@gmail.com>
//
// This software is distributed under the terms of the AGPL v3.0 license.
// See the LICENSE file at the root of this project for more details.
//
//-----------------------------------------------------------------------------

#ifndef LEXER_H
#define LEXER_H

#include <stdlib.h>

#define INITIAL_CAPACITY 8

typedef struct {
    // This is supposed to be NULL terminated
    char** tokens_list;
    size_t n;
    size_t capacity;
} tokens;

tokens tokenize (const char* s);

#endif //LEXER_H