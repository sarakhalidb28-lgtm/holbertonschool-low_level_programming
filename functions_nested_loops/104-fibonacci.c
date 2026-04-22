#include <stdio.h>

/**
 * main - prints first 98 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long a1 = 1, a2 = 2;
	unsigned long h1 = 0, h2 = 0;
	unsigned long n1, n2;
	int i;

	printf("%lu, %lu", a1, a2);

	for (i = 3; i <= 98; i++)
	{
		n1 = a1 + a2;
		n2 = h1 + h2;

		if (n1 >= 1000000000)
		{
			n2 += 1;
			n1 -= 1000000000;
		}

		if (n2 > 0)
			printf(", %lu%09lu", n2, n1);
		else
			printf(", %lu", n1);

		a1 = a2;
		a2 = n1;
		h1 = h2;
		h2 = n2;
	}

	printf("\n");

	return (0);
}
