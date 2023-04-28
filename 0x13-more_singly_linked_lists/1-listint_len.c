#include "lists.h"
/**
 * listint_len - returns the nnumber of elements in a linked list.
 * @h:linked list.
 * Return:number of nides.
 */
size_t listint_len(const listint_t *h)
{
	size_t numb = 0;

	while (h)
	{
		numb++;
		h = h->next;
	}
	return (numb);
}
