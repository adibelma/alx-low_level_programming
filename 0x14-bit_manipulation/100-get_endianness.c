#include "main.h"

/**
 * get_endianness - Checks the endianness if is little or big
 * Return: 0 for big endian, or 1 if little endian
 */
int get_endianness(void)
{
	unsigned int a = 1;
	char *e = (char *) &a;

	return (*e);
}
