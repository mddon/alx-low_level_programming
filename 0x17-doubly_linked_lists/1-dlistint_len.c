#include "lists.h"

/**
 * dlistint_len - This function counts the number of elements in a
 * linked dlistint_t list.
 *
 * @h: The head of the dlistint_t list.
 *
 * Return: return the number of elements in the dlistint_t list.
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t nodes = 0;

	if (h != NULL)
	{
		do {
			nodes++;
			h = h->next;
		} while (h != NULL);
	}

	return (nodes);
}
