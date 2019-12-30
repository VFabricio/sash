#ifndef LEXER_H
#define LEXER_H

#include <stdlib.h>

#define INITIAL_CAPACITY 8

typedef struct {
    char** tokens_list;
    size_t n;
    size_t capacity;
} tokens;

tokens tokenize (const char* s);

#endif //LEXER_H