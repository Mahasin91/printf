#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf Make By Self
 * @format: Format string
 * @ more args prints
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
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
                break;
            }

            case 's':
            {
                const char *str = va_arg(args, const char *);
                while (*str)
                {
                    write(1, str, 1);
                    count++;
                    str++;
                }
                break;
            }
            case '%':
                write(1, "%", 1);
                count++;
                break;
            default:
                write(1, "%", 1);
                write(1, format, 1);
                count += 2;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}
