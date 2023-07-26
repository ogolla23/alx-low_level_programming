#include "shell.h"
/**
* add_node - puts a node at the beginning of the list
* @head: head node address
* @str: string 
* @num: index used in history.
* Return: size.
*/
list_t *add_node(list_t **head, const char *str, int num)
{
list_t *new_head;
if (!head)
return (NULL);
new_head = malloc(sizeof(list_t));
if (!new_head)
return (NULL);
_memset((void *)new_head, 0, sizeof(list_t));
new_head->num = num;
if (str)
{
new_head->str = _strdup(str);
if (!new_head->str)
{
free(new_head);
return (NULL);
}
}
new_head->next = *head;
*head = new_head;
return (new_head);
}
/**
* add_node_end – puts a node at the end of the list
* @head: head node address
* @str: string field.
* @num: index used in history
* Return: size of list
*/
list_t *add_node_end(list_t **head, const char *str, int num)
{
list_t *new_node, *node;
if (!head)
return (NULL);
node = *head;
new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);
_memset((void *)new_node, 0, sizeof(list_t));
new_node->num = num;
if (str)
{
new_node->str = _strdup(str);
if (!new_node->str)
{
free(new_node);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
node->next = new_node;
}
else
*head = new_node;
return (new_node);
}
/**
* print_list_str – shows the string  of a list_t linked list
* @h: first node pointer.
* Return: size of list
*/
size_t print_list_str(const list_t *h)
{
size_t i = 0;
while (h)
{
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
i++;
}
return (i);
}
/**
* delete_node_at_index – removes the node of an index
* @head: first node address.
* @index: index of a node to remove.
* Return: 1 on success and 0 on failure
*/
int delete_node_at_index(list_t **head, unsigned int index)
{
list_t *node, *prev_node;
unsigned int i = 0;
if (!head || !*head)
return (0);
if (!index)
{
node = *head;
*head = (*head)->next;
free(node->str);
free(node);
return (1);
}
node = *head;
while (node)
{
if (i == index)
{
prev_node->next = node->next;
free(node->str);
free(node);
return (1);
}
i++;
prev_node = node;
node = node->next;
}
return (0);
}
/**
* free_list – A function that clears all nodes of a list.
* @head_ptr: pointer to head node.
* Return: Nothing.
*/

