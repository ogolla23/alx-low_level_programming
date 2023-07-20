#include "shell.h"
int write_history(info_t *info)
{
int fd;
    char *filename = get_history_file(info);
    if (!filename)
        return (-1);

    fd = open_history_file(filename);
    free(filename);
    if (fd == -1)
        return (-1);

    write_history_to_file(info, fd);
    close(fd);
    return (1);
}

int open_history_file(char *filename)
{
    return open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
}

void write_history_to_file(info_t *info, int fd)
{
    list_t *node = NULL;
    for (node = info->history; node; node = node->next)
    {
        _putsfd(node->str, fd);
        _putfd('\n', fd);
    }
    _putfd(BUF_FLUSH, fd);
}
