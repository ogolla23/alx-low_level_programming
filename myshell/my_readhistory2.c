#include "shell.h"

int read_history(info_t *info)
{
int fd;
int linecount;
  char *filename = get_history_file(info);
  if (!valid_history_file(filename))
    return 0;

  fd = open_history_file(filename);
  if (fd == -1)
    return 0;

  linecount = read_history_from_file(info, fd);
  close(fd);
  free(filename);
  return linecount;
}

char *get_history_file(info_t *info);

int valid_history_file(char *filename)
{
return filename != NULL;
}

int open_history_file(char *filename);

int read_history_from_file(info_t *info, int fd)
{
int i;
  char buf[READ_BUF_SIZE + 1];
  int last = 0;

  while (read(fd, buf, READ_BUF_SIZE) > 0) {
    buf[READ_BUF_SIZE] = 0;
    for (i = 0; i < READ_BUF_SIZE; i++)
      if (buf[i] == '\n'){
        build_history_list(info, buf + last, info->histcount++);
        last = i + 1;
      }
  }

  if (last < READ_BUF_SIZE)
    build_history_list(info, buf + last, info->histcount++);
  return info->histcount;
}
