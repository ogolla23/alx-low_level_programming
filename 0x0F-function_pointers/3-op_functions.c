#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - Adds two numbers a and b
 * @a: first number.
 * @b: second number.
 * Return:sum of a and b.
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - subtracts two numbers a and b
 * @a: first number.
 * @b: second number.
 * Return:difference of a and b.
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - multiplies two numbers.
 * @a: first number.
 * @b: second number.
 * Return:product of a and b.
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - divides 2 numbers a and b
 * @a: first number.
 * @b: second number.
 * Return:quotient of a and b.
 */
int op_div(int a, int b)
{
	return (a / b);
}
/**
 * op_mod - remainder of the division of 2 numbers
 * @a: first number.
 * @b: second number.
 * Return: The remainder of the division of a by b.
 */
int op_mod(int a, int b)
{
	return (a % b);
}
