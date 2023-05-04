#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index in a dec num
 * @n: num to found
 * @index: idx of bit
 *
 * Return: The value of the bit at index or -1,
 * if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int v_bit;

	if (index > 63)
		return (-1);

	v_bit = (n >> index) & 1;

	return (v_bit);
}
