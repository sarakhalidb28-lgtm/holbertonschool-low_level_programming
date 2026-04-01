#include <stdio.h>

/**
 * main - prints the largest prime factor of 612852475143
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long n = 612852475143;
	unsigned long factor = 2;
	unsigned long max_factor = 0;

	while (n % 2 == 0)
	{
		max_factor = 2;
		n /= 2;
	}

	for (factor = 3; factor * factor <= n; factor += 2)
	{
		while (n % factor == 0)
		{
			max_factor = factor;
			n /= factor;
		}
	}

	if (n > 1)
		max_factor = n;

	printf("%lu\n", max_factor);

	return (0);
}
