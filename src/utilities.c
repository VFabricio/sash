#include <stdio.h>
#include "error.h"
#include "utilities.h"
#include "wrappers.h"

void print_prompt()
{
    print("> ");
}

void print_welcome_message()
{
    print("Welcome to sash, the Super Awesome Shell\n");
}

char* slice(const char* s, size_t start, size_t end)
{
    if (start > end) { 
        error_quit(NEGATIVE_LENGTH_SLICE,
            "FATAL ERROR: tried to compute a negative length string slice!");
    }
    size_t len = end - start;
    char* ret = alloc(len + 1);
    if (snprintf(ret, len, "%s", (s + start)) < 0) {
        error_quit(BAD_SNPRINTF, "FATAL ERROR: snprintf failed!");
    }
    return ret;
}