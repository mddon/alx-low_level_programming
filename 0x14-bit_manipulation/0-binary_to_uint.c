#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: binary.
 *
 * Return: unsigned int.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i_decimal = 0;

	if (!b)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);

		i_decimal = (i_decimal * 2) + (*b - '0');
		b++;
	}

	return (i_decimal);
}
