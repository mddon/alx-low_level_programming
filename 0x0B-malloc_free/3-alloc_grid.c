#include "main.h"
#include <stdlib.h>

/**
 * **alloc_grid - creates a two dimensional array of ints
 * @width: width of the matrix
 * @height: height of the matrix
 *
 * Return: pointer to the created matrix (Success)
 * or NULL (Error)
 */
int **alloc_grid(int width, int height)
{
	int **array;
	int k, x;

	if (height <= 0 || width <= 0)
		return (NULL);

	array = (int **) malloc(sizeof(int *) * height);

	if (array == NULL)
		return (NULL);

	for (k = 0; k < height; k++)
	{
		array[k] = (int *) malloc(sizeof(int) * width);
		if (array[k] == NULL)
		{
			free(array);
			for (x = 0; x <= k; x++)
				free(array[x]);
			return (NULL);
		}
	}

	for (k = 0; k < height; k++)
	{
		for (x = 0; x < width; x++)
		{
			array[k][x] = 0;
		}
	}
	return (array);
}
