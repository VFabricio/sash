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

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void error_quit(int status, const char* msg)
{
    if (msg != NULL) {
        fprintf(stderr, "%s", msg);
    }
    exit(status);
}