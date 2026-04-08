#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: the integer found in the string
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int started;
	int result;
	int digit;

	i = 0;
	sign = 1;
	started = 0;
	result = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			digit = s[i] - '0';

			if (sign == -1)
				result = (result * 10) - digit;
			else
				result = (result * 10) + digit;
		}
		else if (started)
		{
			break;
		}

		i++;
	}

	return (result);
}
