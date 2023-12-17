#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in an array of integers
 *                        using Interpolation Search.
 * @array: Input array.
 * @size: Size of the array.
 * @value: Value to search for.
 *
 * Return: Index of the number if found, otherwise -1.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t position, lower, upper;
	double factor;

	if (array == NULL)
		return (-1);

	lower = 0;
	upper = size - 1;

	while (lower <= upper)
	{
		factor = (double)(upper - lower) / (array[upper] - array[lower]) * (value - array[lower]);
		position = (size_t)(lower + factor);

		printf("Value checked array[%d]", (int)position);

		if (position >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
		{
			printf(" = [%d]\n", array[position]);
		}

		if (array[position] == value)
			return ((int)position);

		if (array[position] < value)
			lower = position + 1;
		else
			upper = position - 1;

		if (lower == upper)
			break;
	}

	return (-1);
}