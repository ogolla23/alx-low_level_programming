#include <stdlib.h>
#include "main.h"

/**
**_memset - memory allocation for array using malloc
* @s: memory location to fill
* @b: char to copy
* @n: number of times to copy b
* Return: pointer to s
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}

/**
**_calloc - allocates memory for array
*@nmemb: number of characters in the array
*@size: size of each element
*Return:pointer to the memory
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *pnt;

	if (nmemb == 0 || size == 0)
	return (NULL);

	pnt = malloc(size * nmemb);

	if (pnt == NULL)
		return (NULL);

	_memset(pnt, 0, nmemb * size);

	return (pnt);
}
