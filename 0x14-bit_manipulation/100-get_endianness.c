#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int position_x;
	char *position_c;

	position_x = 1;
	position_c = (char *) &position_x;

	return ((int)*position_c);
}
