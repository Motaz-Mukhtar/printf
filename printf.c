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
	va_list valist;
	int i = 0, j;
	int length = 0;
	char *str;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	if (format == NULL || format == 0)
		return (-1);
	va_start(valist, format);
	while (format[i] != '\0')
	{
		j = 0;
		if (format[i] == '%')
		{
			str = va_arg(valist, char *);
			if (str ==  (char *)0)
				printf("(null)");
			else
			{
			if (format[i + 1] == 's')
			{
				str = va_arg(valist, char*);
				while (str[j] && !(str[j] <= 0))
				{
					putchar(str[j]);
					j++;
					length++;
				}
				length -= 1;
			}
			}
			if (format[i + 1] == 'c')
				fprintf(stdout, "%c", va_arg(valist, int));
			if (format[i + 1] == 'd')
				fprintf(stdout, "%d", va_arg(valist, int));
			i += 1;
		}
		else
			if (format[i] != '\0')
				fprintf(stdout, "%c", format[i]);
		i++;
		length++;
	}
	va_end(valist);
	return (length);
}
