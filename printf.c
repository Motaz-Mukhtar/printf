#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
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
					printf("%s", va_arg(ap, char *));
				if (format[i + 1] == 'c')
					printf("%c", va_arg(ap, int));
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
