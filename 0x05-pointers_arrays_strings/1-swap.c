#include "main.h"
/**
 * swap_int- swaps the values of two integers
 * in our case a and b
 * @a:intager a
 * @b:integer b
 */
void swap_int(int *a, int *b)

{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}
