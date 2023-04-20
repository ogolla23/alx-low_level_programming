#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_numbers - prints numbers follwd by new line
 * @separator:String to be printed
 * @n:integers apssed to the function
 * @...:variable argumnts
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list argu;
	unsigned int i;

	va_start(argu, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(argu, int));

		if (i != (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");

	va_end(argu);
}
