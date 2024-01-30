#include <stdio.h>
#include <stdarg.h>

/*
 * @brief custom printf function solutions and implementation
 */

/**
 *myprintf -  custom printf function that supports a subsets of
 *format specifiers.
 *
 * @format: The format stringg.
 * @param format the format string.
 * @...: variable arguments to be formatted according to the
 * format strings.
 *
 * Return: the number of characters printed to the console.
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
			putchar(*format);
			count++;
	} else
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
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		format++;
	}

	va_end(args);
	return (count);
}
