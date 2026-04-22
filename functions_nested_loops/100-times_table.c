#include "main.h"

/**
 * print_times_table - prints n times table
 * @n: number
 */
void print_times_table(int n)
{
	int i, j, r;

	if (n < 0 || n > 15)
		return;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			r = i * j;

			if (j)
			{
				_putchar(',');
				_putchar(' ');
				if (r < 100)
					_putchar(' ');
				if (r < 10)
					_putchar(' ');
			}

			if (r >= 100)
				_putchar((r / 100) + '0');
			if (r >= 10)
				_putchar(((r / 10) % 10) + '0');
			_putchar((r % 10) + '0');
		}
		_putchar('\n');
	}
}
