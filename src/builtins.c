#include <stdlib.h>
#include <string.h>
#include "builtins.h"
#include "wrappers.h"

void builtin_exit(tokens t) {
    exit(EXIT_SUCCESS);
}

// WARNING: the three following definitions must always be kept in sync.
// BE EXTREMELY CAREFUL TO ENSURE THIS!!!

size_t number_builtins = 1;
char* builtin_names[] = {"exit"};
void (*builtins[])(tokens t) = {builtin_exit};

bool is_builtin(tokens t)
{
    for(size_t i = 0; i < number_builtins; i++) {
        if(strcmp(t.tokens_list[0], builtin_names[i]) == 0) {
            return true;
        }
    }
    return false;
}

void run_builtin(tokens t)
{
    for(size_t i = 0; i < number_builtins; i++) {
        if(strcmp(t.tokens_list[0], builtin_names[i]) == 0) {
            builtins[i](t);
        }
    }
}