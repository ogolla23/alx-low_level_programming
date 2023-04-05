#include "main.h"
/**
 * _strlen_recursion - Returns the length of string
 * @s:string input
 * Return:Length of string
 */
int _strlen_recursion(char *s)
{
	int lenstr = 0;

	if (*s)
	{
		lenstr++;
		lenstr += _strlen_recursion(s + 1);
	}
	return (lenstr);
}
