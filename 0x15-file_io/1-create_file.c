#include "main.h"
/**
* create_file - creates a file and writes text into it
* @filename: The name of the file to create
* @text_content: The text to write into the file
*Return: 1 on success and -1 if filename is NULL or on failure.
*/
int create_file(const char *filename, char *text_content)
{
	int fd, wr;
	size_t len = 0;

	if (!filename)
		return (-1);
	if (text_content)
		while (text_content[len])
			len++;
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	wr = write(fd, text_content, len);
	if (wr == -1)
		return (-1);
	close(fd);
	return (1);
}
