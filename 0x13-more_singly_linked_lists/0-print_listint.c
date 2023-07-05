#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints all the elements of a list.
 * @h: the head of a list.
 *
 * Return: this is the numbers of nodes.
 */

size_t print_listint(const listint_t *h)
{
	size_t nnodes = 0;
	
	for (; h != NULL; h = h->next)
	{
		printf("%d\n", h->n);
		nnodes++;
	}
	
	return nnodes;
}

