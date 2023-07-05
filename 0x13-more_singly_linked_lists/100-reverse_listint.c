#include "lists.h"

/**
 * reverse_listint - reverses a linked list.
 * @head: head of a list.
 *
 * Return: pointer to the first node.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *b;
	listint_t *xn;

	b = NULL;
	xn = NULL;

	while (*head != NULL)
	{
		xn = (*head)->next;
		(*head)->next = b;
		b = *head;
		*head = xn;
	}

	*head = b;
	return (*head);
}
