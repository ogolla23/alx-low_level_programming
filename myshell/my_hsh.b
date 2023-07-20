int hsh(info_t *info, char **av)
{
  while (get_input(info) != -1) {
    if (is_builtin(info))
      handle_builtin(info);
    else
      find_cmd(info);

    free_info(info, 0);
  }
  return handle_exit(info);
}

ssize_t get_input(info_t *info)
{
  // ... (Same as before)
}

int is_builtin(info_t *info)
{
  if (*info->arg == '\n')
    return 0;
  char *argv[] = {info->argv[0], NULL};
  return find_builtin(argv) != NULL;
}

int handle_builtin(info_t *info)
{
  builtin_func_t f;
  f = find_builtin(info->argv);
  return f(info);
}

void find_cmd(info_t *info)
{
char *path = NULL;
  info->path = info->argv[0];

  path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
  if (path) {
    info->path = path;
    fork_cmd(info);
  } else if ((interactive(info) || _getenv(info, "PATH=")
              || info->argv[0][0] == '/') && is_cmd(info, info->argv[0])) {
    fork_cmd(info);
  } else if (*(info->arg) != '\n') {
    print_error(info, "not found\n");
  }
}

int handle_exit(info_t *info)
{
  if (info->err_num == -1)
    exit(info->status);
  exit(info->err_num);
}


