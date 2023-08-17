#include "lists.h"

/**
 * print_dlistint - Prints all elements of a dlistint_t list.
 *
 * @h: This is the head of the dlistint_t list.
 *
 * Return: return number of nodes in the list.
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t nodes = 0;

	do {
		printf("%d\n", h->n);
		h = h->next;
		nodes++;
	} while (h != NULL);

	return (nodes);
}
