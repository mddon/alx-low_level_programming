#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * malloc_checked - allocate a space
 * @b: unsigned int
 * Return: void
 * if malloc fails, status value is equal to 98.
 */
void *malloc_checked(unsigned int b)
{
	char *em;

	em = malloc(b);
	if (em == NULL)
	{
		exit(98);
	}
	return (em);
}
