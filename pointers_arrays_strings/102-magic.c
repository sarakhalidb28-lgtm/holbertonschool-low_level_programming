#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int n;
	int *p;
	int a[5];
	a[0] = 1024;
	a[1] = 402;
	a[2] = 98;
	a[3] = 6;
	a[4] = 7;
	p = &n;
	/* write your line of code here */
	*(p + 5) = 98;
	/* ...so that this prints 98\n */
	printf("a[2] = %d\n", a[2]);
	return (0);
}
