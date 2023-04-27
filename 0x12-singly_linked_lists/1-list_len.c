#include <stdlib.h>
#include "lists.h"
/**
 * list_len - returns the number of elements
 * in a linked linked list_t list
 * @h:list_t lists pointer
 * Return:number of elements
 */
size_t list_len(const list_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}
	return (num);
}
