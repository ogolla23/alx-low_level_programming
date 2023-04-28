#include "lists.h"
/**
 * free_listint_safe - frees lists with a loop
 * @h:first pointer.
 * Return:number of elements on freed list.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t lent = 0;
	listint_t *temp;
	int diffnt;

	if (!h || !*h)
		return (0);
	while (*h)
	{
		diffnt = *h - (*h)->next;
		if (diffnt > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			lent++;
		}
		else
		{
			free(*h);
			*h = NULL;
			lent++;
			break;
		}
	}
	*h = NULL;
	return (lent);
}
