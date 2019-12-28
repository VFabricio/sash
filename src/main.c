#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"
#include "wrappers.h"

int main()
{
    print_welcome_message();
    char* input = read_line();
    if (input == NULL) {
        return EXIT_SUCCESS;
    }
}