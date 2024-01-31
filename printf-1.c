#include "main.h"

/**
 * spec_1 - specifier for %d and %i
 * @arg: list of arguments
 * @format: the conversion specifer
 *
 * Return: return the number of characters
 */

int spec_1(va_list arg, const char *format)
{
	int count = 0, num;
	char c = '%';

	if (*format == 'd' || *format == 'i')
	{
		num = va_arg(arg, int);

		if (num == '\0')
			count += write(1, "0", 1);
		else
			count += print_num(num);
	}
	else
	{
		count += write(1, &c, 1);
		count += write(1, format, 1);
	}

	return (count);
}

/**
 * print_num - print integers
 * @num: integer to be printed
 *
 * Return: numbers of character
 */

int print_num(int num)
{
	int count = 0, temp;
	int isNeg, i = 0;

	isNeg = num;

	if (num == INT_MIN)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}

	if (num < 0)
		num = -1 * num;

	temp = num;

	if (num == 0)
	{
		count++;
		return (1);
	}
	else
	{
		while (temp != 0)
		{
			temp /= 10;
			count++;
		}
	}
	print_buffer(count, num, i, isNeg);

	if (isNeg < 0)
		count++;

	return (count);
}

