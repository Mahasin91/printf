#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
void write_char(char c, int *count);

void write_str(const char *str, int *count);

void write_int(int num, int *count);

int _printf(const char *format, ...);

void write_binary(unsigned int n);
#endif
