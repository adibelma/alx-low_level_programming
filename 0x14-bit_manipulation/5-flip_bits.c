#include "main.h"

/**
 * flip_bits - Returns number of bits you would need
 * to flip to get from one number to another
 * @n: 1st number
 * @m: 2nd number
 *
 * Return: Number of bits changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, cnt = 0;
	unsigned long int cur;
	unsigned long int ex = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		cur = ex >> i;
		if (cur & 1)
			cnt++;
	}

	return (cnt);
}
