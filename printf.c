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
	int i = 0;
	int length = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	if (format == NULL)
		return (-1);
	va_start(valist, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
				if (format[i + 1] == 's')
					fprintf(stdout, "%s", va_arg(valist, char *));
				if (format[i + 1] == 'c')
					fprintf(stdout, "%c", va_arg(valist, int));
				if (format[i + 1] == 'd')
					fprintf(stdout, "%d", va_arg(valist, int));
				i += 1;
		}
		else
			if (format[i])
				fprintf(stdout, "%c", format[i]);
		i++;
		length++;
	}
	va_end(valist);
	return (length);
}

int main(void)
{
	int len, len2, len3, len4;
	
	len = _printf("Let's print a simple sentence.\n");
	len2 = printf("Let's print a simple sentence.\n");
	len3 = _printf("%c", 'S');
	len4 =  printf("%c", 'S');
	fflush(stdout);
	if ((len != len2) || (len3 != len4)) 
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
