#include <stdio.h>
#include <unistd.h>
#include "main.h"
/**
*_putchar - A function that writes characters
*@c: Input character
*Return: 1 on sucess, -1 on error
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
