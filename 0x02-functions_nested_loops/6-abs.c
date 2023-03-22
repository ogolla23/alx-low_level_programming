#include "main.h"
/**
* _abs - Prints the sign of a number
* @c: The number to be computed
* Return: The absolute value of a number or zero 
*/

int _abs(int c)

{

	if (c < 0)
	{
	int abs_val;

	abs_val = c * -1;
	return (abs_val);
	}
	return (c);
}
