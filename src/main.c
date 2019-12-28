#include <stdio.h>
#include "utilities.h"
#include "wrappers.h"

int main()
{
    print_welcome_message();
    char* input = read_line();
    printf("%s", input);
}