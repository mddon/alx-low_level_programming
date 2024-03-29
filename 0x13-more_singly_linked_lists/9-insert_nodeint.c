#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node
 * at a given position.
 * @head: head of a list.
 * @idx: index of the list where the new node is
 * added.
 * @n: integer element.
 *
 * Return: the address of the new node, or NULL if it
 * failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int r;
	listint_t *new_node;
	listint_t *k;

	k = *head;

	if (idx != 0)
	{
		for (r = 0; r < idx - 1 && k != NULL; r++)
		{
			k = k->next;
		}
	}

	if (k == NULL && idx != 0)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		new_node->next = k->next;
		k->next = new_node;
	}

	return (new_node);
}
