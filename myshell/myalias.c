#include "shell.h"
int _myalias(info_t *info) 
{
  if (is_listing_mode(info)) {
    list_aliases(info);
    return 0; 
  }
  
  alias_operation_mode(info);
  return 0; 
}

int is_listing_mode(info_t *info) 
{
  return info->argc == 1; 
}

void list_aliases(info_t *info) 
{
  list_t *node = info->alias;
  while (node) {
    print_alias(node);
    node = node->next; 
  }
}  

void alias_operation_mode(info_t *info) 
{
  int i;
  char *p = NULL;
  for (i = 1; info->argv[i]; i++) {
    p = _strchr(info->argv[i], '=');
    if (p)
      set_alias(info, info->argv[i]);
    else
      print_alias(node_starts_with(info->alias, info->argv[i], '='));
  } 
}

