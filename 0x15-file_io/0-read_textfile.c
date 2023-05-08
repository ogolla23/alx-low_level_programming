#include "main.h"
#include <stdlib.h>
/**
*read_textfile - Reads a text file and prints
*it to the POSTIX standard out.
*@filename: The name of the file to read.
*@letters: The number of letters to be read and pprinted
*Return: The actual number of letters read and printed or
*0 if filename is NULL or the function fails.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *ch;
	ssize_t fd, w, r;

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	ch = malloc(sizeof(char) * letters);
	if (!ch)
		return (0);
	r = read(fd, ch, letters);
	w = write(STDOUT_FILENO, ch, r);

	free(ch);
	close(fd);
	return (w);
}
