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

/**
* write_int - Helper function to write a int
* @num: int to write
* @count: Pointer to the count of characters
*/
void write_int(int num, int *count)
{
char buffer[12];
int length = 0;

if (num == 0)
{
buffer[length++] = '0';
}
else
{
if (num < 0)
{
write_char('-', count);
num = -num;
}
while (num > 0)
{
buffer[length++] = num % 10 + '0';
num /= 10;
}
for (int i = 0, j = length - 1; i < j; i++, j--)
{
char temp = buffer[i];
buffer[i] = buffer[j];
buffer[j] = temp;
}
}
write_str(buffer, count);
}
