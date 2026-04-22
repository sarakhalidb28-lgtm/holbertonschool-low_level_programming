#include <stdio.h>

/**
 * main - sum of even Fibonacci numbers <= 4000000
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long int a = 1, b = 2, next;
	unsigned long int sum = 0;

	while (b <= 4000000)
	{
		if (b % 2 == 0)
			sum += b;

		next = a + b;
		a = b;
		b = next;
	}

	printf("%lu\n", sum);

	return (0);
}
