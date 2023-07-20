int write_history(info_t *info)
{
  char *filename = get_history_file(info);
  if (!valid_history_file(filename))
    return -1;

  int fd = open_history_file(filename);
  if (fd == -1)
    return -1;

  write_history_to_file(info, fd);
  close(fd);
  free(filename);
  return 1;
}

char *get_history_file(info_t *info)
{
char *buf, *dir;
  dir = _getenv(info, "HOME=");
  if (!dir)
    return NULL;

  buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
  if (!buf)
    return NULL;
  buf[0] = 0;
  _strcpy(buf, dir);
  _strcat(buf, "/");
  _strcat(buf, HIST_FILE);

  return buf;
}
int valid_history_file(char *filename)
{
  return filename != NULL;
}

int open_history_file(char *filename)
{
  return open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
}

void write_history_to_file(info_t *info, int fd)
{
  list_t *node = NULL;
  for (node = info->history; node; node = node->next) {
    _putsfd(node->str, fd);
    _putfd('\n', fd);
  }
  _putfd(BUF_FLUSH, fd);
}


