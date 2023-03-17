#include <stdio.h>
/**
*main -Another program that writes combinations of single digits
*Return:Always 0 (Success)
*/
#include <stdio.h>

int main(void)
{
int i = 0;
for (i = 0; i < 10; i++)
{
putchar(i + '0');
if (i != 9)
{
putchar(',');
putchar(' ');
}
}
putchar('.');
return (0);
}
