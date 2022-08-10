#include "main.h"
#include <string.h>
/**
 * _printf - do the smae thing like printf fucntion
 * @format: format String.
 * Return: Always 0.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, length;

	length = strlen(format);
	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);
	while (i < length)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
			{
				if (format[i + 1] == 's')
					print_str(ap);
				if (format[i + 1] == 'c')
					print_char(ap);
				i += 1;
			}
		}
		else
			putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (length);
}
/**
 * print_char - char function print
 * @ap: va_list type
 * Return 1.
 */
int print_char(va_list ap)
{
	char c = va_arg(ap, int);

	if (c == '\0')
		return (write(1, &c, 1));
	putchar(c);
	return (1);
}
/**
 * print_str - string function print
 * @ap: va_list type
 * Return 0.
 */
int print_str(va_list ap)
{
	char *argument = va_arg(ap, char *);
	int sum = 0;

	if (!argument)
	{
		sum += _puts("(null)", 0);
		return (sum);
	}
	return (_puts(argument, 0));
}
