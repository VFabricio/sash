#ifndef BUILTINS_H
#define BUILTINS_H

#include <stdbool.h>
#include "lexer.h"


bool is_builtin(tokens t);
void run_builtin(tokens t);

#endif //BUILTINS_H