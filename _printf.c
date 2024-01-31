#include "main.h"

/**
 * _printf - printf 
 * @format: formatted string
 *
 * Return: return the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(arg, format);

	while (*format)
	{
		if (*format != '%')
		{
			count++;
			write(1, format, sizeof(char));
		}
		else
		{
			format++;
			if (*format == '\0' || *format == ' ')
			{
				return (-1);
			}
			else
				count += spec(arg, format);
		}
		format++;
	}

	va_end(arg);

	return (count);
}
