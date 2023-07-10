#include "main.h"
#include <stdlib.h>

/**
* read_textfile - Reads a text file and prints it to the POSIX standard output.
* @filename: The name of the file to be read.
* @letters: The number of letters to be read and printed.
*
* Return: The actual number of letters read and printed,
*         or 0 if the function fails or filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buf;
ssize_t fd, w, t;

if (!filename)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

buf = malloc(sizeof(char) * letters);
if (!buf)
return (0);

t = read(fd, buf, letters);
w = write(STDOUT_FILENO, buf, t);

free(buf);
close(fd);

return (w);
}
