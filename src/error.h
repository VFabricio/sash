#ifndef ERROR_H
#define ERROR_H

#define UNKNOWN_ERROR 1
#define PRINT_ERROR 2
#define INVALID_GETLINE 3
#define OOM_GETLINE 4

void error_quit(int status, const char* msg);

#endif //ERROR_H