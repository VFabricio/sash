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

#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "error.h"
#include "wrappers.h"

void* alloc(size_t size) {
    if (size == 0) {
        error_quit(ZERO_SIZE_ALLOC, "FATAL ERROR: tried to allocate a zero size buffer!");
    }
    void* ptr = malloc(size);
    if (ptr == NULL) {
        if (errno == ENOMEM) {
            error_quit(OOM_ALLOC, "FATAL ERROR: could not allocate memory!");
        }
        else {
            error_quit(UNKNOWN_ERROR, "FATAL ERROR: unknown error when calling alloc!");
        }
    }
    return ptr;
}

void* resize_alloc(void* ptr, size_t size) {
    if (size == 0) {
        error_quit(ZERO_SIZE_ALLOC, "FATAL ERROR: tried to reallocate a buffer to zero size!");
    }
    void* new_ptr = realloc(ptr, size);
    if (new_ptr == NULL) {
        if (errno == ENOMEM) {
            error_quit(OOM_ALLOC, "FATAL ERROR: could not allocate memory when resizing a buffer!");
        }
        else {
            error_quit(UNKNOWN_ERROR, "FATAL ERROR: unknown error when calling resize_alloc!");
        }
    }
    return new_ptr;
}

void print(const char* s)
{
    if (printf("%s", s) < 0) {
        error_quit(PRINT_ERROR, "FATAL ERROR: could not write to the console!");
    }
}

char* read_line()
{
    char* buf = NULL;
    size_t size = 0;
    int nread = getline(&buf, &size, stdin);
    if (nread == -1) return NULL;
    if (nread < 0) {
        if (errno == EINVAL) {
            error_quit(INVALID_GETLINE,
                "FATAL ERROR: invalid arguments passed to 'getline'!");
        }
        if (errno == ENOMEM) {
            error_quit(OOM_GETLINE,
                "FATAL ERROR: could not allocate memory while reading input!");
        }
        error_quit(UNKNOWN_ERROR, "FATAL ERROR: unknown error when calling read_line!");
    }
    return buf;
}