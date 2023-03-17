#include <stdio.h>
/**
*main -A program that writes alphabets except p and q
*Return:Always 0 (Success)
*/

int main(void)
{
char c;

for (c = 'a'; c <= 'z'; c++)
if (c != 'q' && c != 'e')
putchar(c);
putchar('\n');

return (0);
}
