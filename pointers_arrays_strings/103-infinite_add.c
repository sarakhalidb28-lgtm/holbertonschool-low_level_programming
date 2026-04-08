#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer for result
 * @size_r: size of buffer
 *
 * Return: pointer to result or 0 if it fails
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k, carry = 0, sum;

	while (n1[i])
		i++;

	while (n2[j])
		j++;

	i--;
	j--;

	k = size_r - 1;
	r[k] = '\0';
	k--;

	while (i >= 0 || j >= 0 || carry)
	{
		if (k < 0)
			return (0);

		sum = carry;

		if (i >= 0)
			sum += n1[i--] - '0';

		if (j >= 0)
			sum += n2[j--] - '0';

		r[k--] = (sum % 10) + '0';
		carry = sum / 10;
	}

	return (&r[k + 1]);
}
