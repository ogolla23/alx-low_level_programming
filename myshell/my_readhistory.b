#include "shell.h"

int read_history(info_t *info)
{
int fd;
ssize_t fsize;
char *buf;
int linecount;

    char *filename = get_history_file(info);
    if (!filename)
        return (0);

    fd = open_history_file(filename);
    free(filename);
    if (fd == -1)
        return (0);

    fsize = get_file_size(fd);
    if (fsize < 2)
        return (0);

    buf = read_file_contents(fd, fsize);
    if (!buf)
        return (0);

    linecount = build_history_from_buffer(info, buf, fsize);
    free(buf);

    trim_history(info);
    renumber_history(info);
    return (info->histcount);
}

int open_history_file(char *filename)
{
    return open(filename, O_RDONLY);
}

ssize_t get_file_size(int fd)
{
    struct stat st;
    if (!fstat(fd, &st))
        return st.st_size;
    return 0;
}

char *read_file_contents(int fd, ssize_t fsize)
{
ssize_t rdlen;
    char *buf = malloc(sizeof(char) * (fsize + 1));
    if (!buf)
        return NULL;

    rdlen = read(fd, buf, fsize);
    buf[fsize] = 0;
    if (rdlen <= 0)
        return (free(buf), NULL);

    close(fd);
    return buf;
}

int build_history_from_buffer(info_t *info, char *buf, ssize_t fsize)
{
    int i, last = 0, linecount = 0;
    for (i = 0; i < fsize; i++)
        if (buf[i] == '\n')
        {
            buf[i] = 0;
            build_history_list(info, buf + last, linecount++);
            last = i + 1;
        }
    if (last != i)
        build_history_list(info, buf + last, linecount++);
    
    info->histcount = linecount;
    return linecount;
}

void trim_history(info_t *info)
{
    while (info->histcount-- >= HIST_MAX)
        delete_node_at_index(&(info->history), 0);
}
