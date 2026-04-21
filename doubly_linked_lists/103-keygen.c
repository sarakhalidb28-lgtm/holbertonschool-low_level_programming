#include <stdio.h>
#include <stdlib.h>

/**
 * main - generates a key for crackme5
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *username;
	int i, sum = 0;

	if (argc != 2)
		return (1);

	username = argv[1];

	for (i = 0; username[i]; i++)
		sum += username[i];

	printf("%d\n", sum);

	return (0);
}
