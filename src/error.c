#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void error_quit(int status, const char* msg)
{
    fprintf(stderr, "%s", msg);
    exit(status);
}