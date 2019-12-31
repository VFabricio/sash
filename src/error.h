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

#ifndef ERROR_H
#define ERROR_H

#define UNKNOWN_ERROR 1
#define PRINT_ERROR 2
#define INVALID_GETLINE 3
#define OOM_GETLINE 4
#define ZERO_SIZE_ALLOC 5
#define OOM_ALLOC 6
#define BAD_SNPRINTF 7
#define NEGATIVE_LENGTH_SLICE 8
#define MAX_THREADS_EXECUTE 9
#define OOM_EXECUTE 10
#define NO_FORK_EXECUTE 11

void error_quit(int status, const char* msg);

#endif //ERROR_H