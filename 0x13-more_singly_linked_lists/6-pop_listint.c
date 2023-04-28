#include "lists.h"
/**
 * pop_listint - delets head node.
 * @head: the head node
 * Return: data in head node or 0.
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int numb;

	if (!head || !*head)
		return (0);
	numb = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;
	return (numb);
}
