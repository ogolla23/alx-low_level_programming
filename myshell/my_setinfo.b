#include "shell.h"

void set_info(info_t *info, char **av)
{
  info->fname = av[0];
  if (has_argument(info)) {
    info->argv = tokenize_argument(info->arg);
    replace_alias(info);
    replace_vars(info);
  }
}

int has_argument(info_t *info);

char **tokenize_argument(char *arg)
{
  return strtow(arg, " \t");
}


