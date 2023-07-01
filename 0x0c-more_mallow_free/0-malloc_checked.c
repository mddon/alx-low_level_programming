#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * malloc_checked - allocate a space
 * @b: unsigned int
 * Return: void
 */
void *malloc_checked(unsigned int b)
{
	void *em;

	em = malloc(b);
	if (em == NULL)
	{
		exit(98);
	}
	return (em);
}
