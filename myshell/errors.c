#include "shell.h"
/**
* _eputs - prints an input string
* @str: the string to be printed
*
* Return: Nothing
*/
void _eputs(char *str)
{
int i = 0;
if (!str)
return;
for (; str[i] != '\0'; i++)
_eputchar(str[i]);
}
/**
* _eputchar - writes the character c to stderr
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
if (write(2, buf, i) == -1)
return (-1);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
/**
* _putfd - writes the character c to given fd
* @c: The character to print
* @fd: The filedescriptor to write to
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putfd(char c, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
if (write(fd, buf, i) == -1)
return (-1);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
/**
* _putsfd - prints an input string
* @str: the string to be printed
* @fd: the filedescriptor to write to
*
* Return: the number of chars put
*/
int _putsfd(char *str, int fd)
{
int i = 0;
if (!str)
return (0);
for (; *str; str++)
i += _putfd(*str, fd);
return (i);
}

