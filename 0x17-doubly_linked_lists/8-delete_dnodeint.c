#include "lists.h"

/**
 * delete_dnodeint_at_index - Function to delete a node from a dlistint_t
 *                            at a given index.
 *
 * @head: Pointer to the head of the dlistint_t.
 * @index: Index of the node to delete.
 *
 * Return: returns 1 on success, and -1 on failure.
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;

	if (*head == NULL)
	{
		return (-1);
	}

	while (index != 0)
	{
		if (current == NULL)
		{
			return (-1);
		}
		current = current->next;
		index--;
	}

	if (current == *head)
	{
		*head = current->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
	}

	else
	{
		current->prev->next = current->next;
		if (current->next != NULL)
		{
			current->next->prev = current->prev;
		}
	}

	free(current);
	return (1);
}
