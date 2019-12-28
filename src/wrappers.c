#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include "error.h"
#include "wrappers.h"

void print(const char* s)
{
    if (printf("%s", s) < 0) {
        error_quit(PRINT_ERROR, "FATAL ERROR: could not write to the console!");
    }
}

char* read_line()
{
    char* buf = NULL;
    size_t size = 0;
    while(true) {
        int nread = getline(&buf, &size, stdin);
        if (nread == -1) continue; //EOF, try again
        if (nread < 0) {
            if (errno == EINVAL) {
                error_quit(INVALID_GETLINE,
                    "FATAL ERROR: invalid arguments passed to 'getline'!");
            }
            if (errno == ENOMEM) {
                error_quit(OOM_GETLINE,
                    "FATAL ERROR: could not allocate memory while reading input!");
            }
            error_quit(UNKNOWN_ERROR, "FATAL ERROR: unkown error!");
        } else break;
    }
    return buf;
}