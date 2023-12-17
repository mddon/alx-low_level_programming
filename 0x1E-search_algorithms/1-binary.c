#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array of integers
 *                 using binary search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description:
 *	- Prints the [sub]array being searched after each change.
 *	- The function uses a binary search algorithm to efficiently locate
 *	  the target value within the given sorted array.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t mid, start, end;

	if (array == NULL)
		return -1;

	for (start = 0, end = size - 1; end >= start;)
	{
		printf("Searching in array: ");
		for (mid = start; mid < end; mid++)
			printf("%d, ", array[mid]);
		printf("%d\n", array[mid]);

		mid = start + (end - start) / 2;

		if (array[mid] == value)
			return mid;

		if (array[mid] > value)
			end = mid - 1;
		else
			start = mid + 1;
	}

	return -1;
}