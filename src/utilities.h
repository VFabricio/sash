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

#ifndef UTILITIES_H
#define UTILITIES_H

void print_prompt();
void print_welcome_message();
char* slice(const char* s, size_t start, size_t end);

#endif // UTILITIES_H