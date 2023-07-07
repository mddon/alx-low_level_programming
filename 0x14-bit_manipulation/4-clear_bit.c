#include "main.h"

/**
 * clear_bit - this sets the value of a bit to 0
 * at a given index.
 * @n: this is a pointer to an unsigned long int.
 * @index: index of the bit.
 *
 * Return: 1 is returend if it works, -1 if it doesn't.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int position_k;

	if (index > 63)
		return (-1);

	position_k = 1 << index;

	if (*n & position_k)
		*n ^= position_k;

	return (1);
}
