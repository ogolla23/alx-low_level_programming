#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main -determines if a number is positive,negative or zero
 * Return:Always 0(Successs)
 */
int main(void)
{
int n;

srand(time(0));
n = rand() - RAND_MAX / 2;
printf("%d ", n);
if (n > 0)
printf("is positive\n");
else if (n == 0)
printf("is zero\n");
else
printf("is negative\n");
return (0);
}
