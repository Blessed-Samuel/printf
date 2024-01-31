#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int _printf(const char *format, ...);
int specifier(va_list arg, const char *format);
int specifier_1(va_list arg, const char *format);
int print_num(int num);
void print_buffer(int count, int num, int i, int isNeg);




#endif
