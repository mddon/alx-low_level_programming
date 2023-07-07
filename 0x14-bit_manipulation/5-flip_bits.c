#include "main.h"

/**
 * flip_bits - prints the number of bits you would
 * need to flip to get from one number to another
 * @n: the first number.
 * @m: the second number.
 *
 * Return: number of bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int kb;

	for (kb = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			kb++;
	}

	return (kb);
}
