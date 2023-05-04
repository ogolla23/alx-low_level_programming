#include "main.h"
/**
 * clear_bit - set the value of a bit to
 * a given index to 0
 * @n:pointer to the number to modify
 * @index:The index of the bit to clear
 * Return: 1 if successful, -1 if an error occurs
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > (sizeof(*n) * 8 - 1))
		return (-1);
	*n &= ~(1UL << index);
	return (1);
}
