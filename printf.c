#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>
#include <string.h>

int _printf(const char *format, ...)
{
	va_list valist;
	int i = 0;
	int length = strlen(format);
	int j;
	char *str;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(valist, format);
	while (i < length)
	{
		j = 0;
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'd':
					{
						printf("%d", va_arg(valist, int));
						i += 1;
					}
					break;
				case 's':
					str = va_arg(valist, char *);
					while (str[j] != '\0')
					{
						putchar(str[j]);
						j++;
					}
					i += 1;
					break;
				case 'c':
					{
						putchar(va_arg(valist, int));
						i += 1;
					}
					break;
				case '%':
					i += 1;
					break;
			}
		}
		else
			putchar(format[i]);
		i++;
	}
	va_end(valist);
	return (length);
}
