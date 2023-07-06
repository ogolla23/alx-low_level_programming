#include "main.h"
#include <unistd.h>
/**
* _putchar - prints a character.
* @c:the character
* Return: 1 on success and -1 on fail.
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
