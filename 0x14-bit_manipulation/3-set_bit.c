#include "main.h"

/**
 * set_bit - Sets the vaue of a bit to 1 at a given index
 * @n: Pointer to the num to change
 * @index: index of bit sets to 1
 *
 * Return: 1 if it works else, -1 if error occured
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1ul << index) | *n);
	return (1);
}
