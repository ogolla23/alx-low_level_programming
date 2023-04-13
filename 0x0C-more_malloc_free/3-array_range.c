#include <stdlib.h>
#include "main.h"

/**
**array_range - a function that creates an
*array of integers
*@min: minimum range of values stored
*@max: maximum range of values stored
*Return: pointer to the created array
*/

int *array_range(int min, int max)
{
	int *pnt;
	int i, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	pnt = malloc(sizeof(int) * size);

	if (pnt == NULL)
		return (NULL);

	for (i = 0; min <= max; i++)
		pnt[i] = min++;

	return (pnt);
}
