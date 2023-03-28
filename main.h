#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent();
int print_int(va_list args);
int print_other(const char *format);
char *itoa(int num, int base);
#endif
