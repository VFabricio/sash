#ifndef ERROR_H
#define ERROR_H

#define UNKNOWN_ERROR 1
#define PRINT_ERROR 2
#define INVALID_GETLINE 3
#define OOM_GETLINE 4
#define ZERO_SIZE_ALLOC 5
#define OOM_ALLOC 6
#define BAD_SNPRINTF 7

void error_quit(int status, const char* msg);

#endif //ERROR_H