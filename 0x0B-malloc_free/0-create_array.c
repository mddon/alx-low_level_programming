#include "main.h"
#include <stdlib.h>

/**
 * *create_array - creates an array of chars, and initializes
 *  it with a specific char.
 *  @ii: char to initialize
 *  @size: number of bytes to allocate
 *
 *  Return: a pointer to the array or null if it fails
 */
char *create_array(unsigned int size, char ii)
{
	char *array = malloc(size);

	if (size == 0 || array == 0)
		return (NULL);
	while (size--)
		array[size] = ii;
	return (array);
}
