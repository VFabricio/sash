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

#ifndef BUILTINS_H
#define BUILTINS_H

#include <stdbool.h>
#include "lexer.h"

bool is_builtin(tokens t);
void run_builtin(tokens t);

#endif //BUILTINS_H