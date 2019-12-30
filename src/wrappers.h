#ifndef WRAPPERS_H
#define WRAPPERS_H

void* alloc(size_t size);
void print(const char* s);
char* read_line();
void* resize_alloc(void* ptr, size_t size);
char* string_copy(const char* s);

#endif //WRAPPERS_H