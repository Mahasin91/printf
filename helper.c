#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
* write_char - Helper function to write a character to stdout
* @c: Character to write
* @count: Pointer to the count of characters
*/
void write_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

/**
* write_str - Helper function to write a string to stdout
* @str: String to write
* @count: Pointer to the count of characters
*/
void write_str(const char *str, int *count)
{
	while (*str)
	{
		write_char(*str, count);
		str++;
	}
}
