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
		write(1, str, 1);
		(*count)++;
		str++;
	}
}

/**
 * write_int - Helper function to write an integer
 * @num: integer to write
 * @count: Pointer to the count of numbers
 */
void write_int(int num, int *count)
{
	char buffer[12];

	int len = 0;

	if (num < 0)
	{
		write(1, "-", 1);
		(*count)++;
		num = -num;
	}
	do	{
		buffer[len++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	while (len > 0)
	{
		write(1, &buffer[--len], 1);
		(*count)++;
	}
}
