#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) of
 * a linked list.
 * @head: head of a list.
 *
 * Return: sum of all the data (n).
 */
int sum_listint(listint_t *head)
{
	int n_sum = 0;

	for (; head != NULL; head = head->next)
	{
		n_sum += head->n;
	}

	return (n_sum);
}
