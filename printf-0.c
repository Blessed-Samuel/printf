#include <stdio.h>
#include <stdarg.h>

int myprintf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;

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
