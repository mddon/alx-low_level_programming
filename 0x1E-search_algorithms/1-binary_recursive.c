#include "search_algos.h"

/**
 * binary_search_recursive - Searches recursively for a value in a sorted array
 *                           of integers using binary search.
 * @array: A pointer to the first element of the [sub]array to search.
 * @start: The starting index of the [sub]array to search.
 * @end: The ending index of the [sub]array to search.
 * @value: The value to search for.
 *
 * Return: If the value is not present, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints the [sub]array being searched after each change.
 */
int binary_search_recursive(int *array, size_t start, size_t end, int value)
{
	size_t mid;

	if (end < start)
		return -1;

	printf("Searching in array: ");
	for (size_t i = start; i < end; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[end]);

	mid = start + (end - start) / 2;

	if (array[mid] == value)
		return mid;
	if (array[mid] > value)
		return binary_search_recursive(array, start, mid - 1, value);
	return binary_search_recursive(array, mid + 1, end, value);
}

/**
 * binary_search - Searches for a value in a sorted array
 *                 of integers using binary search.
 * @array: Pointer to the first element of the array to search.
 * @value: The value to search for.
 * @size: The number of elements in the array.
 *
 * Return: NULL if the value is not present or the array, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints the [sub]array being searched after each change.
 */
int binary_search(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return -1;

	return binary_search_recursive(array, 0, size - 1, value);
}