#include "main.h"

/**
 * itoa - Integer to ASCII. Converts an int to a string
 * @num: int
 * @base: number base
 *
 * Return: string representation of i
 */
char *itoa(int num, int base)
{
	static char buf[32];
	int i = 0, j = 0, k = 0;
	int is_negative = 0;

	if (num < 0)
	{
		is_negative = 1;
		num *= -1;
	}

	while (num > 0)
	{
		buf[i++] = (num % base) + '0'; /* convert to ASCII code */
		num /= base;
	}

	if (is_negative)
		buf[i++] = '-';

	k = i - 1;
	while (j < k)
	{
		char temp = buf[k];

		buf[k--] = buf[j];
		buf[j++] = temp;
	}

	buf[i] = '\0';

	return (buf);
}

/**
 * _printf - a function that produces output according to a format.
 * @format: string to print with support for conversion specifiers
 *
 * Return: number of bytes printed
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
				count += print_char(args);
				break;
			case 's':
				count += print_string(args);
				break;
			case '%':
				count += print_percent();
				break;
			case 'd':
			case 'i':
				count += print_int(args);
				break;
			default:
				count += print_other(format);
				break;
			}
		}
		else
			count += print_other(format);
		format++;
	}
	va_end(args);

	return (count);
}

