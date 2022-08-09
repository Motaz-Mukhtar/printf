#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * _printf - This fucntion make the same way like pritf
 * @format: String
 * Return: 0.
 */
int _printf(const char *format, ...)
{
	int i;
	int length;
	va_list ap;
	int key = 1;

	va_start(ap, format);
	length = strlen(format);
	if (format == NULL)
		return (0);
	if (length < 0)
		return (0);
	while (i = 0; i < length; i++)
	{
		if (format[i] == '%' && (format[i + 1] != 'd' && format[i + 1] != 's' &&
		format[i + 1] != 'c'))
			key = 0;
		if (format[i] == '%' && format[i + 1] == '%')
			i += 1;
		if (format[i] == '%' && key == 1)
		{
			if (format[i + 1] == 'd')
				fprintf(stdout, "%d", va_arg(ap, int));
			if (format[i + 1] == 's')
				fprintf(stdout, "%s", va_arg(ap, char *));
			if (format[i + 1] == 'c')
				fprintf(stdout, "%c", va_arg(ap, int));
			if (format[i + 1] == 'i')
				fprintf(stdout, "%i", va_arg(ap, int));
		}
		else
		{
			if ((format[i] == 'd' && format[i - 1] == '%') ||
			(format[i] == 's' && format[i - 1] == '%') ||
			(format[i] == 'c' && format[i - 1] == '%') ||
			(format[i] == 'i' && format[i - 1] == '%'))
			{
				continue;
			}
			else
				printf("%c", format[i]);
		}
	}
	va_end(ap);
	return (length);
}
