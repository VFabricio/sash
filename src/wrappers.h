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

#ifndef WRAPPERS_H
#define WRAPPERS_H

void* alloc(size_t size);
void print(const char* s);
char* read_line();
void* resize_alloc(void* ptr, size_t size);
char* string_copy(const char* s);

#endif //WRAPPERS_H