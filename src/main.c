#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "utilities.h"
#include "wrappers.h"

int main()
{
    print_welcome_message();
    while (true) {
        char* input = read_line();
        if (input == NULL) {
            return EXIT_SUCCESS;
        }
        tokens t = tokenize(input);
    }
}