#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - function to print to stdout
 * @format: formatted string
 *
 * Return: int
 */

int _printf(const char *format, ...)
{
	va_list ap;
	char const *p, *sval;
	int ival;
	double dval;
	char cval;
	int count = 0;

	va_start(ap, format);
	for (p = format; *p; p++, count++)
	{
		if (*p != '%')
		{
		putchar (*p);
		continue;
	}
	switch (*++p)
	{
	case 'd':
	case 'i':
	ival = va_arg(ap, int);
	printf("%i", ival);
	break;
	case 'f':
	dval = va_arg(ap, double);
	printf("%f", dval);
	break;
	case 'c':
	cval = va_arg(ap, int);
	printf("%c", cval);
	break;
	case 's':
		for (sval = va_arg(ap, char *); *sval; sval++)
			putchar (*sval);
	break;
	default:
	putchar (*p);
	break;
	}
}
va_end(ap);
return (count);
}
