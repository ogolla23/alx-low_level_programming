#include "main.h"

/**
* append_text_to_file - Appends text at the end of a file.
* @filename: The name of the file to append to.
* @text_content: The text to append to the file.
*
* Return: 1 on success,
*         -1 on failure, if filename is NULL or if the file does not exist
*         or if the user lacks write permissions.
*/
int append_text_to_file(const char *filename, char *text_content)
{
int o, w;
size_t len = 0;

if (!filename)
return (-1);

if (text_content)
while (text_content[len])
len++;

o = open(filename, O_WRONLY | O_APPEND);
if (o == -1)
return (-1);

w = write(o, text_content, len);
if (w == -1)
return (-1);

close(o);

return (1);
}
