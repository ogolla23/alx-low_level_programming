#include <stdio.h>
/**
*main -Another program that writes combinations of single digits
*Return:Always 0 (Success)
*/

int main(void)
{
int i = 0;
while (i <= 9)
{
putchar(i + '0');
if (i != 9)
{
putchar(',');
putchar(' ');
}
i++;
}
return (0);
}
