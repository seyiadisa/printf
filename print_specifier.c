#include "main.h"

/**
 * print_char - prints a char
 * @args: argument list
 *
 * Return: number of bytes printed
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @args: argument list
 *
 * Return: number of bytes printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	while (str[len])
		len++;

	return (write(1, str, len));
}

/**
 * print_percent - prints a percent sign
 *
 * Return: number of bytes printed
 */
int print_percent(void)
{
	return (write(1, "%", 1));
}

/**
 * print_int - prints an integer
 * @args: argument list
 *
 * Return: number of bytes printed
 */
int print_int(va_list args)
{
	int i = va_arg(args, int);
	char *str = itoa(i, 10);
	int len = 0;

	while (str[len])
		len++;

	return (write(1, str, len));
}

/**
 * print_other - prints non-format characters
 * @format: string to print
 *
 * Return: number of bytes printed
 */
int print_other(const char *format)
{
	return (write(1, format, 1));
}
