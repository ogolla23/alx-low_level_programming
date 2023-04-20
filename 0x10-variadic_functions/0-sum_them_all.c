#include "variadic_functions.h"
#include<stdarg.h>
/**
 * *sum_them_all - sums up all its parameters
 * @n: number of parameters
 * @...:variable number of parameters
 * Return:sumation of all parameters if n== 0
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list argu;
	unsigned int i;
	int sum = 0;

	va_start(argu, n);

	for (i = 0; i < n; i++)
		sum += va_arg(argu, int);

	va_end(argu);
	return (sum);
}
