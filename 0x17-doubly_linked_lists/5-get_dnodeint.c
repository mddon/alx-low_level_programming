#include "lists.h"

/**
 * get_dnodeint_at_index - A function to locate a node in a dlistint_t list.
 *
 * @head: The head of the dlistint_t list.
 * @index: Node to locate.
 *
 * Return: Return NULL if the node does not exist.
 *         Otherwise - the address of the located node.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	while (index != 0)
	{
		if (head == NULL)
		{
			return (NULL);
		}
		head = head->next;
		index--;
	}

	return (head);
}
