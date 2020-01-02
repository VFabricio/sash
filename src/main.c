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
#include <stdlib.h>
#include "builtins.h"
#include "execute.h"
#include "lexer.h"
#include "utilities.h"
#include "wrappers.h"

int main()
{
    print_welcome_message();
    while (true) {
        print_prompt();
        char* input = read_line();
        if (input == NULL) { //EOF
            return EXIT_SUCCESS;
        }
        tokens t = tokenize(input);
        if (t.n != 0) {
            if (is_builtin(t)) {
                run_builtin(t);
            } else {
                execute(t);
            } 
        }
        free(input);
        free_tokens(t);
    }
}