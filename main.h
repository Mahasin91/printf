#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
void write_char(char c, int *count);

void write_str(const char *str, int *count);

int _printf(const char *format, ...);

int _putchar(char c);

#endif
