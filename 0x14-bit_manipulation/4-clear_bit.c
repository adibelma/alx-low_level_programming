#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at given index
 * @n: Pointer to num to change
 * @index: Index of bit to clear
 *
 * Return: 1 if it worked, or -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1ul << index) & *n);
	return (1);
}
