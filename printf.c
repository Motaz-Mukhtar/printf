#include "main.h"
#include <math.h>
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - do the smae thing like printf fucntion
 * @format: format String.
 * Return: Always 0.
 */
int _printf(const char *format, ...)
{
	va_list valist;
	int i = 0, j, length = 0;
	char *str;

	if (!format || (format[0] == '%' && format[1] == '\0') ||
	     format == NULL || format == 0)
		return (-1);
	va_start(valist, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && (format[i + 1] == 's' ||
		    format[i + 1] == 'c' || format[i + 1] == 'd'
		    || format[i + 1] == '%' || format[i + 1] == 'i'))
		{
			if (format[i + 1] == 's')
			{
				str = va_arg(valist, char *);
				if (str == NULL)
					str = "(null)";
				for (j = 0; str[j]; j++)
				{
					fprintf(stdout, "%c", str[j]);
					length++;
				}
				length -= 1;
			}
			if (format[i + 1] == 'c')
				fprintf(stdout, "%c", va_arg(valist, int));
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				int num = va_arg(valist, int);
				fprintf(stdout, "%d", num);
				if (num == 0)
					return (1);
				if (num < 0)
				{
					num *= (-1);
					length += 1;
				}
				while (num > 0 || num < 0)
				{
					num = num / 10;
					length++;
				}
				length -= 1;
			}
			if (format[i + 1] == '%')
				fprintf(stdout, "%%");
			i += 1;
		}
		else
			fprintf(stdout, "%c", format[i]);
		length++;
	}
	va_end(valist);
	return (length);
}
