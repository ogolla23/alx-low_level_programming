#include "lists.h"

/**
 * reverse_listint - a func that reverses a listint_t.
 * @head:first node.
 * Return:Pointer to head in new list.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}
	*head = prev;
	return (*head);
}
