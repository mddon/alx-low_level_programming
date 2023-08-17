#include "lists.h"

/**
 * insert_dnodeint_at_index - Function to inserts a new node in a dlistint_t
 *                            list at a given position.
 * @head: A pointer to the head of the dlistint_t list.
 * @index: The position to insert the new node.
 * @n: Integer for the new node to contain.
 *
 * Return: It returns NULL if the function fails.
 *         Otherwise - the address of the new node.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **head, unsigned int index, int n)
{
	dlistint_t *tmp = *head, *new_node;

	if (index == 0)
	{
		return (add_dnodeint(head, n));
	}

	for (; index != 1; index--)
	{
		tmp = tmp->next;
		if (tmp == NULL)
		{
			return (NULL);
		}
	}

	if (tmp->next == NULL)
	{
		return (add_dnodeint_end(head, n));
	}

	new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = n;
	new_node->prev = tmp;
	new_node->next = tmp->next;
	tmp->next->prev = new_node;
	tmp->next = new_node;
	return (new_node);
}
