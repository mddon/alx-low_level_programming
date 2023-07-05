#include "lists.h"

/**
 * pop_listint - deletes the head node of
 * a linked list
 * @head: head of a list.
 *
 * Return: head node's data.
 */
int pop_listint(listint_t **head)
{
	int h_node_data;
	listint_t *h_node;
	listint_t *current;

	if (*head == NULL)
		return (0);

	current = *head;

	h_node_data = current->n;

	h_node = current->next;

	free(current);

	*head = h_node;

	return (h_node_data);
}
