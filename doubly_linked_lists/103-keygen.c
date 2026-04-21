#include <stdio.h>
#include <stdlib.h>

/**
 * main - generates a valid key for crackme5
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *username;
	unsigned long hash = 0;
	int i;

	if (argc != 2)
		return (1);

	username = argv[1];

	for (i = 0; username[i]; i++)
		hash = hash * 31 + username[i];

	printf("%lu\n", hash);

	return (0);
}
