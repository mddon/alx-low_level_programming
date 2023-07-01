#include "main.h"
#include <stdlib.h>
/**
 * array_range - creates an array of integers.
 * @min: minimum value.
 * @max: maximum value.
 *
 * Return: pointer to the newly created array.
 * if man > mix, returns NULL.
 * if malloc fails, returns NULL.
 */
int *array_range(int min, int max)
{
	int *d;
	int em;

	if (min > max)
		return (NULL);

	d = malloc(sizeof(*d) * ((max - min) + 1));

	if (d == NULL)
		return (NULL);

	for (em = 0; min <= max; em++, min++)
		d[em] = min;

	return (d);
}
