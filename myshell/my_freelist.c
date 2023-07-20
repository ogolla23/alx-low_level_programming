#include "shell.h"

void free_list(list_t **head_ptr)
{
list_t *node;
  if (!valid_list(head_ptr))
    return;

  node = *head_ptr;
  while (node) {
    list_t *next_node = node->next;
    free_node(node);
    node = next_node;
  }
  *head_ptr = NULL;
}

int valid_list(list_t **head_ptr)
{
  return head_ptr != NULL && *head_ptr != NULL;
}

void free_node(list_t *node)
{
  free(node->str);
  free(node);
}


