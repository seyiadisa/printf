#include "main.h"

/**
 * itoa - Integer to ASCII. Converts an int to a string
 * @num: int
 * @base: number base
 *
 * Return: string representation of i
 */
char *itoa(long num, int base)
{
	static char buf[64] = {0};
	int i = 0, j = 0, k = 0;
	int is_negative = 0;

	if (num < 0)
	{
		is_negative = 1;
		num *= -1;
	}

	while (num > 0)
	{
		int remainder = num % base;

		if (remainder < 10)
			buf[i++] = remainder + '0'; /* convert to ASCII code */
		else
			buf[i++] = "0123456789abcdef"[remainder];
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
			count += handle_conversion(format, args);
		}
		else
			count += print_other(format);
		format++;
	}
	va_end(args);

	return (count);
}

/**
 * handle_conversion - a function that checks the specifiers.
 * @format: string to print with support for conversion specifiers
 * @args: arguments list
 *
 * Return: number of bytes printed
 */
int handle_conversion(const char *format, va_list args)
{
	int count = 0;

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
	case 'b':
		count += print_binary(args);
		break;
	case 'u':
		count += print_unsigned_int(args);
		break;
	case 'o':
		count += print_octal(args);
		break;
	case 'x':
	case 'X':
		count += print_hexadecimal(args, *format);
		break;
	default:
		write(1, (char *) --format, 1);
		count += print_other(++format);
		break;
	}

	return (count);
}
