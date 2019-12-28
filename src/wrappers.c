#include <stdio.h>
#include "error.h"
#include "wrappers.h"

void print(const char* s)
{
    if (printf("%s", s) < 0) {
        error_quit(PRINT_ERROR, "FATAL ERROR: could not write to the console!");
    }
}