#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_all - prints everything
 * @format:types of arguments passed to function
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	char *str, *sep = "";

	va_list all;

	va_start(all, format);

	if (format)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 1:
				printf("%s%c", sep, va_arg(all, int));
				break;
				case 2:
				printf("%s%d", sep, va_arg(all, int));
				break;
				case 3:
				printf("%s%f", sep, va_arg(all, double));
				break;
				case 4:
				str = va_arg(all, char *);
				if (!str)
					str = "(nil)";
				printf("%s%s", sep, str);
				break;
				default:
				i++;
				continue;
			}
			sep = ",";
			i++;
		}
	}
}



