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

int main(void)
{
	int len, len2;

	len = _printf("Let's print a simple sentence.\n");
	len2 = printf("Let's print a simple sentence.\n");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
