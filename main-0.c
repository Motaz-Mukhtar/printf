#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
	int len, len2;
	len = _printf("Let's print a simple sentence.\n");
	len2 = printf("Let's print a simple sentence.\n");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lenghts differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
