#include <stdio.h>

/**
 * main - prints first 98 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long a1 = 1, a2 = 2, b1, b2;
	unsigned long h1, h2;
	int i;

	printf("%lu, %lu", a1, a2);

	for (i = 3; i <= 98; i++)
	{
		/* تقسيم الرقم إلى جزئين */
		h1 = a1 / 1000000000;
		h2 = a2 / 1000000000;
		b1 = a1 % 1000000000;
		b2 = a2 % 1000000000;

		/* جمع الأجزاء */
		h1 = h1 + h2;
		b1 = b1 + b2;

		if (b1 >= 1000000000)
		{
			h1 += 1;
			b1 -= 1000000000;
		}

		if (h1 > 0)
			printf(", %lu%09lu", h1, b1);
		else
			printf(", %lu", b1);

		a1 = a2;
		a2 = h1 * 1000000000 + b1;
	}

	printf("\n");

	return (0);
}
