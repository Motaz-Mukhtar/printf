#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);

int convert_alpha_numeric(int nb, int upper)
{
	if (nb >= 10)
		return (nb - 10 + ((upper) ? 'A' : 'a'));
	else
		return (nb + '0');
}

char *convert_base(unsigned long nb, unsigned int base, int upper)
{
	int i =0;
	char *str;
	unsigned long nbr = nb;

	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	str = malloc(sizeof(char) * i + 2);
	if (!str)
		return (0);
	str[i + 1] = '\0';

	while (i >= 0)
	{
		nbr = nb % base;
		str[i] = convert_alpha_numeric(nbr, upper);
		nb /= base;
		i--;
	}
	return (str);
}

int _puts(char *str, int ascii)
{
	char *s;
	int i = 0, sum = 0;
	
	while (str[i])
	{
		if (((str[i] >= 0 && str[i] < 32) || str[i] >= 127) && ascii)
		{
			s = convert_base(str[i], 16, 1);
			sum += write(1, "\\x", 2);
			if (str[i] >= 0 && str[i] < 16)
				sum += putchar('0');
			sum += _puts(s, 0);
			free(s);
			i++;
		}
		else
		{
			sum += putchar(str[i]);
			i++;
		}
	}
	return (sum);
}

int print_number(int n)
{
	unsigned int nb;
	int count = 0;

	nb = n;
	if (n < 0)
	{
		putchar('-');
		count ++;
		nb = -nb;
	}
	if (nb <= 9)
	{
		count += putchar(nb + '0');
		return (count);
	}
	if (nb > 9)
	{
		count += print_number(nb / 10) + 1;
		putchar(nb % 10 + '0');
		return (count);
	}
	return (0);
}
int print_char(va_list ap);

int print_str(va_list ap);

int print_nbr(va_list ap)
{
	return (print_number(va_arg(ap, int)));
}
int print_percent(va_list args __attribute__((unused)))
{
	return (putchar('%'));
}
int print_rot13(va_list ap);

#endif
