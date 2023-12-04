#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
* _printf - Custom printf Make By Self
* @format: Format string
* Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				write_char(va_arg(args, int), &count);
				break;
			case 's':
				write_str(va_arg(args, const char *), &count);
				break;
				case 'd':
				_printf("%d", va_arg(args, int));
				count++;
				break;
				case 'i':
				_printf("%d", va_arg(args, int));
				count++;
				break;
			case '%':
				write_char('%', &count);
				break;
			default:
				write_char('%', &count);
				write_str(format, &count);
				count++;
			}
		}
		else
		{
			write_char(*format, &count);
		}
		format++;
	}
	va_end(args);
	return (count);
}
