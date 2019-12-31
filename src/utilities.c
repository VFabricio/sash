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

#include <stdio.h>
#include "error.h"
#include "utilities.h"
#include "wrappers.h"

void print_prompt()
{
    print("> ");
}

void print_welcome_message()
{
    print("Welcome to sash, the Super Awesome Shell\n");
}

char* slice(const char* s, size_t start, size_t end)
{
    if (start > end) { 
        error_quit(NEGATIVE_LENGTH_SLICE,
            "FATAL ERROR: tried to compute a negative length string slice!");
    }
    size_t len = end - start;
    char* ret = alloc(len + 1);
    if (snprintf(ret, len, "%s", (s + start)) < 0) {
        error_quit(BAD_SNPRINTF, "FATAL ERROR: snprintf failed!");
    }
    return ret;
}