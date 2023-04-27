#include <stdlib.h>
#include "lists.h"
/**
 * free_list - frees a linkeed list.
 * @head:list_t freed list in list_t
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}
