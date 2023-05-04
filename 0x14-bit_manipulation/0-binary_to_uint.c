#include "main.h"

/**
 * binary_to_uint - converts a binary num to unsigned int
 * @b: str containing bin num
 *
 * Return: the converted number or 0 if,
 * there is one or more char in the str b that is not 0 or 1,
 * b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int val-d = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		val-d = 2 * val-d + (b[i] - '0');
	}

	return (val-d);
}
