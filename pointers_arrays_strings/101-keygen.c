#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random valid passwords
 *
 * Return: Always 0.
 */
int main(void)
{
	int sum = 0;
	int rand_char;

	srand(time(NULL));

	while (sum < 2772)
	{
		rand_char = rand() % 94 + 33;

		if (sum + rand_char > 2772)
			continue;

		putchar(rand_char);
		sum += rand_char;
	}

	return (0);
}
