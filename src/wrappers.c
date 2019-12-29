#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "error.h"
#include "wrappers.h"

void* alloc(size_t size) {
    if (size == 0) {
        error_quit(ZERO_SIZE_ALLOC, "FATAL ERROR: tried to allocate a zero size buffer!");
    }
    void* ptr = malloc(size);
    if (ptr == NULL) {
        if (errno == ENOMEM) {
            error_quit(OOM_ALLOC, "FATAL ERROR: could not allocate memory!");
        }
        else {
            error_quit(UNKNOWN_ERROR, "FATAL ERROR: unknown error!");
        }
    }
    return ptr;
}

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
    int nread = getline(&buf, &size, stdin);
    if (nread == -1) return NULL;
    if (nread < 0) {
        if (errno == EINVAL) {
            error_quit(INVALID_GETLINE,
                "FATAL ERROR: invalid arguments passed to 'getline'!");
        }
        if (errno == ENOMEM) {
            error_quit(OOM_GETLINE,
                "FATAL ERROR: could not allocate memory while reading input!");
        }
        error_quit(UNKNOWN_ERROR, "FATAL ERROR: unknown error!");
    }
    return buf;
}

const char* string_copy(const char* s)
{
    size_t size = strlen(s) + 1;
    char* copy = alloc(size);
    if (snprintf(copy, size, "%s", s) < 0) {
        error_quit(BAD_SNPRINTF, "FATAL ERROR: snprintf failed!");
    }
    return copy;
}