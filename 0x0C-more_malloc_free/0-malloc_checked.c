#include <stdlib.h>
#include "main.h"

/**
* *malloc_checked - memory allocation using malloc
* @b:bytes size to allocate
*Return:pointer to allocated memory
*/

void *malloc_checked(unsigned int b)
{
	void *pnt;

	pnt =  malloc(b);

	if (pnt == NULL)
		exit(98);

	return (pnt);
}
