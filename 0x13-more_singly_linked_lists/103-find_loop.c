#include "lists.h"
/**
 * find_listint_loop -finds loop in linked list.
 * @head:first node.
 * Return:pointer to where loop starts or NULL.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *dark = head;
	listint_t *light = head;

	if (!head)
		return (NULL);
	while (dark && light && light->next)
	{
		light = light->next->next;
		dark = dark->next;
		if (light == dark)
		{
			dark = head;
			while (dark != light)
			{
				dark = dark->next;
				dark = light->next;
			}
			return (light);
		}
	}
	return (NULL);
}
