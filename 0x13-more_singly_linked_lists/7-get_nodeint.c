#include "lists.h"
/**
 * get_nodeint_at_index - returns the nth node.
 * @head:first node.
 * @index:the nth node
 * Return:pointer to the nth node.
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *temp = head;
	unsigned int i = 0;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}
	return (temp ? temp : NULL);
}
