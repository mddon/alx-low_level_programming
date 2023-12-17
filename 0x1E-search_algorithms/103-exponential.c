#include "search_algos.h"
#include <stdio.h>

/**
 * exponential_search - Searches for a value in a sorted array
 *                      of integers using exponential search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints a value every time it is compared in the array.
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t currentIndex = 0, right;

    if (array == NULL)
        return (-1);

    if (array[currentIndex] != value)
    {
        for (currentIndex = 1; currentIndex < size && array[currentIndex] <= value; currentIndex *= 2)
            printf("Value checked array[%lu] = [%d]\n", (unsigned long)currentIndex, array[currentIndex]);
    }

    right = currentIndex < size ? currentndex : size - 1;
    printf("Value found between indexes [%lu] and [%lu]\n", (unsigned long)(currentIndex / 2), (unsigned long)right);
    return binary_search(array, currentIndex / 2, right, value);
}
