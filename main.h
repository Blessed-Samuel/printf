#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define CHAR_TYPE 1
#define STRING_TYPE 2
#define PERCENT_TYPE 3
#define BINARY_TYPE 5

/* Prototypes for handling %d and %i specifiers */
int _print_deci(const char *format, ...);
int print_int(va_list args);
int print_int_helper(int num);


#endif
