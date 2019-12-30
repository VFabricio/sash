#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "builtins.h"
#include "lexer.h"
#include "utilities.h"
#include "wrappers.h"

void execute(tokens t) {
    return;
}

int main()
{
    print_welcome_message();
    while (true) {
        char* input = read_line();
        if (input == NULL) { //EOF
            return EXIT_SUCCESS;
        }
        tokens t = tokenize(input);
        if (t.n == 0) continue;
        if (is_builtin(t)) {
            run_builtin(t);
        } else {
            execute(t);
        } 
    }
}
