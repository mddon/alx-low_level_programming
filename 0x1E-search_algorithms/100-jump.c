#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Function to search for a value in an array of integers.
 * @array: Array input.
 * @size: Size of the array.
 * @value: Value to search for.
 *
 * Return: Index of the number if found, otherwise -1.
 */
int jump_search(int *array, size_t size, int value)
{
	int current, jump, blocks, prev_index;

	if (array == NULL || size == 0)
		return (-1);

	jump = (int)sqrt((double)size);
	blocks = 0;
	prev_index = current = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", current, array[current]);

		if (array[current] == value)
			return (current);

		blocks++;
		prev_index = current;
		current = blocks * jump;
	} while (current < (int)size && array[current] < value);

	printf("Value found between indexes [%d] and [%d]\n", prev_index, current);

	for (; prev_index <= current && prev_index < (int)size; prev_index++)
	{
		printf("Value checked array[%d] = [%d]\n", prev_index, array[prev_index]);

		if (array[prev_index] == value)
			return (prev_index);
	}

	return (-1);
}
