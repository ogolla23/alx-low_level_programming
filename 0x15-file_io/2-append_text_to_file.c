#include "main.h"
/**
* append_text_to_file - Appends text at the end of a file
* @filename: The name of the file to append to
*@text_content: The text to append to the file
*Return: 1 on success and -1 if the user lacks write permissio
*or if the file does not exist.
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int apd, wr;
	size_t len = 0;

	if (!filename)
		return (-1);
	if (text_content)
		while (text_content[len])
			len++;
	apd = open(filename, O_WRONLY | O_APPEND);
	if (apd == -1)
		return (-1);
	wr = write(apd, text_content, len);
	if (wr == -1)
		return (-1);
	close(apd);
	return (1);
}
