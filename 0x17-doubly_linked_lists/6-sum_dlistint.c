#include "lists.h"

/**
 * sum_dlistint - This is function to sum all the data of a dlistint_t list.
 * @head: The head of the dlistint_t list.
 *
 * Return: The sum of all the data.
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head != NULL)
	{
		do {
			sum += head->n;
			head = head->next;
		} while (head != NULL);
	}
	return (sum);
}
