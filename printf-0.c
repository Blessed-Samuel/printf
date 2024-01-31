#include <stdio.h>
#include "main.h"
#include <stdarg.h>

/**
 * myprintf - Custom printf function with limited functionality.
 * @format: The format string.
 * @...: Variable arguments.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;

	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			fputc(*format, stdout);
			count++;
		}
		else
		{
			switch (*++format)
			{
			case 'c':
				count += fprintf(stdout, "%c", va_arg(args, int));
				break;
			case 's':
				count += fprintf(stdout, "%s", va_arg(args, char *));
				break;
			case '%':
				count += fprintf(stdout, "%%");
				break;
			default:
				fputc('%', stdout);
				fputc(*format, stdout);
				count += 2;
				break;
			}
		}
		format++;
	}

	va_end(args);
	return (count);
}
