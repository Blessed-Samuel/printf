#include <stdio.h>
#include "main.h"
#include <stdarg.h>

/**
 * _putchar - prints a character to stdout
 * @c: The character to print
 * Return: The number of characters printed (always 1)
 */
int _putchar(char c)
{
	putchar(c);
	return (1);
}

/**
 * print_char - prints a character
 * @args: The argument list
 * @count: The count of characters printed
 * Return: The updated count of characters printed
 */
int print_char(va_list args, int count)
{
	char *str = va_arg(args, char*);

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		count += _putchar(*str++);
	}

	return (count);
}

/**
 * print_str - prints a string
 * @args: The argument list
 * @count: The count of characters printed
 * Return: The updated count of characters printed
 */
int print_str(va_list args, int count)
{
	char *str = va_arg(args, char*);

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		count += _putchar(*str++);
	}

	return (count);
}

/**
 * print_integer - prints an integer
 * @args: The argument list
 * @count: The count of characters printed
 * Return: The updated count of characters printed
 */
int print_integer(va_list args, int count)
{
	int value = va_arg(args, int);

	count += fprintf(stdout, "%d", value);
	return (count);
}

/**
 * _printf - custom printf function that supports a subset of
 * format specifiers.
 * @format: The format string.
 * @...: variable arguments to be formatted according to the format strings.
 * Return: the number of characters printed to the console.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
			count += _putchar(*format);
		else
		{
			format++;
			if (*format == '\0')
				break;

			switch (*format)
			{
			case 'c':
				count = print_char(args, count);
				break;

			case 'd':
			case 'i':
				count = print_integer(args, count);
				break;

			case 's':
				count = print_str(args, count);
				break;

			case '%':
				count += _putchar('%');
				break;

			default:
				count += _putchar('%');
				count += _putchar(*format);
				break;
			}
		}
		format++;
	}

	va_end(args);
	return (count);
}
