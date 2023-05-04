#include "main.h"

/**
 * print_binary - prints the binary representation of a decimal number
 * @n: num to print in bin
 */
void print_binary(unsigned long int n)
{
	int i, cnt = 0;
	unsigned long int cur;

	for (i = 63; i >= 0; i--)
	{
		cur = n >> i;

		if (cur & 1)
		{
			_putchar('1');
			cnt++;
		}
		else if (cnt)
			_putchar('0');
	}
	if (!cnt)
		_putchar('0');
}
