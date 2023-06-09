#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

char *create_buffer(char *file);
void close_file(int fd);

/**
* create_buffer - Allocates memory for a buffer.
* @file: The name of the file the buffer is storing characters for.
*
* Return: A pointer to the newly-allocated buffer.
*/
char *create_buffer(char *file)
{
char *buffer;

buffer = malloc(sizeof(char) * BUFFER_SIZE);
if (!buffer)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
exit(99);
}

return (buffer);
}

/**
* close_file - Closes a file descriptor.
* @fd: The file descriptor to be closed.
*/
void close_file(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
* main - Copies the contents of one file to another file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
*
* Return: 0 on success,
*         97 if the number of arguments is incorrect,
*         98 if the source file does not exist or cannot be read,
*         99 if the destination file cannot be created or written to,
*         100 if a file descriptor cannot be closed.
*/
int main(int argc, char *argv[])
{
int from, to, r, w;
char *buffer;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buffer = create_buffer(argv[2]);
from = open(argv[1], O_RDONLY);

if (from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}

to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

while ((r = read(from, buffer, BUFFER_SIZE)) > 0)
{
w = write(to, buffer, r);

if (w == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buffer);
close_file(from);
close_file(to);
exit(99);
}
}

free(buffer);
close_file(from);
close_file(to);

return (0);
}
