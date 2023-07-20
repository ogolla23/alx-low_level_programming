#include "shell.h"
/**
* _erratoi - converts a string to an integer
* @s: the string to be converted
* Return: 0 if no numbers in string, converted number otherwise
* -1 on error
*/
int _erratoi(char *s)
{
unsigned long int result = 0;
if (*s == '+')
s++;
for (; *s; s++)
{
if (*s >= '0' && *s <= '9')
{
result = result * 10 + (*s - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}
/**
* print_error - prints an error message
* @info: the parameter & return info struct
* @estr: string containing specified error type
* Return: 0 if no numbers in string, converted number otherwise
* -1 on error
*/
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}
/**
* print_d - function prints a decimal (integer) number (base 10)
* @input: the input
* @fd: the filedescriptor to write to
*
* Return: number of characters printed
*/
int print_d(int input, int fd)
{
int digit;
int count = 0;
if (input < 0)
{
_putfd('-', fd);
count++;
input = -input;
}
if (input == 0)
{
_putfd('0', fd);
count++;
}
else
{
int temp = input;
int digits = 0;
while (temp > 0)
{
temp /= 10;
digits++;
}
temp = input;
while (digits > 0)
{
int power = 1;
int i = 1;
for (; i < digits; i++)
{
power *= 10;
}
digit = temp / power;
_putfd('0' + digit, fd);
count++;
temp -= digit * power;
digits--;
}
}
return (count);
}
/**
* convert_number - converter function, a clone of itoa
* @num: number
* @base: base
* @flags: argument flags
*
* Return: string
*/
char *convert_number(long int num, int base, int flags)
{
static char buffer[50];
char *ptr = &buffer[49];
unsigned long n = (flags & CONVERT_UNSIGNED) ? (unsigned long)num : (num < 0 ? -num : num);
const char *digits = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
*ptr = '\0';
do {
*--ptr = digits[n % base];
n /= base;
} while (n != 0);
if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
*--ptr = '-';
}
return (ptr);
}
/**
* remove_comments - function replaces first instance of '#' with '\0'
* @buf: address of the string to modify
*Return: Always 0;
*/
void remove_comments(char *buf)
{
char *p = buf;
while (*p)
{
if (*p == '#' && (p == buf || *(p - 1) == ' '))
{
*p = '\0';
break;
}
p++;
}
}
