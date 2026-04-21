#include <stdio.h>

/**
 * main - generates a valid key for crackme5
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *s;
	int i, key = 0;

	if (argc != 2)
		return (1);

	s = argv[1];

	for (i = 0; s[i]; i++)
		key += s[i] * (i + 1);

	printf("%d\n", key);

	return (0);
}
