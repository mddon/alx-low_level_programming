#include "main.h"

/**
 * set_bit - sets the value of a bit to 1
 * at a given index.
 * @n: pointer to an unsigned long int.
 * @index: index of the bit.
 *
 * Return: 1 if it worked, -1 if it didn't.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int position_m;

	if (index > 63)
		return (-1);

	position_m = 1 << index;
	*n = (*n | position_m);

	return (1);
}
