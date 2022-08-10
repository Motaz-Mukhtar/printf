#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(va_list ap);
int print_str(va_list ap);
int print_str_unprintable(va_list ap);
int print_str_reverse(va_list ap);
int print_ptr(va_list ap);
int print_nbr(va_list ap);
int print_unsigned(va_list ap);
int print_binary(va_list ap);
int print_octal(va_list ap);
int print_hexa_lower(va_list ap);
int print_hexa_upper(va_list ap);
int print_percent(va_list ap);
int print_number(va_list ap);
int print_rot13(va_list ap);

/**
 * struct flags_printf - struct 
 * @c: flag
 * @f: pointer
 */

typedef struct flags_printf
{
	char *c;
	int (*f)(va_list);
} flags_p;

#endif
