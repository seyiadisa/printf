#include "main.h"

/**
 * print_binary - prints a binary
 * @args: argument list
 *
 * Return: integer
 */
int print_binary(va_list args)
{
	int i = va_arg(args, int);
	char *str = itoa(i, 2);
	int len = 0;

	while (str[len])
		len++;

	return (write(1, str, len));
}

/**
 * print_unsigned_int - prints an unsigned int
 * @args: argument list
 *
 * Return: integer
 */
int print_unsigned_int(va_list args)
{
	unsigned int i = va_arg(args, unsigned int);
	char *str = itoa(i, 10);
	int len = 0;

	while (str[len])
		len++;

	return (write(1, str, len));
}

/**
 * print_octal - prints an octal
 * @args: argument list
 *
 * Return: integer
 */
int print_octal(va_list args)
{
	unsigned int i = va_arg(args, unsigned int);
	char *str = itoa(i, 8);
	int len = 0;

	while (str[len])
		len++;

	return (write(1, str, len));
}

/**
 * print_hexadecimal - prints an hexadecimal
 * @args: argument list
 * @letter: checks lowercase or uppercase
 *
 * Return: integer
 */
int print_hexadecimal(va_list args, char letter)
{
	unsigned int i = va_arg(args, unsigned int);
	char *str = itoa(i, 16);
	int len = 0;

	while (str[len])
	{
		if (str[len] >= 97 && str[len] <= 102 && letter == 'X')
		{
			str[len] -= 32;
		}
		len++;
	}

	return (write(1, str, len));
}
