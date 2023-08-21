#include "main.h"
/**
 * _puts - outputs string folloed by new line
 *@str:string
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
		_putchar('\n');
}
