#include "shell.h"

int main(int ac, char **av)
{
  info_t info[] = { INFO_INIT };
  initialize_shell(info, ac, av);
  int status = start_shell(info);
  cleanup_shell(&info);
  return status;
}

void initialize_shell(info_t *info, int ac, char **av)
{
info_t *info = malloc(sizeof(info_t));
  if (!info)
    return NULL;
  init_info_struct(info);

  info->fname = av[0];
  info->readfd = 0;

  if (ac == 2) {
    info->readfd = open(av[1], O_RDONLY);
  }

  populate_env_list(info);
  read_history(info);

  return info;
}

int start_shell(info_t *info)
{
  return (hsh(info, av));
}

void cleanup_shell(info_t **info)
{
write_history(*info);
  free_info(*info, 1);
  free(*info);
  *info = NULL;
}


