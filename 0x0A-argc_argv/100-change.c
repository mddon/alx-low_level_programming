#include <stdio.h>
#include <stdlib.h>

/**
 * main - Print the minimum number of coins
 * @argc: arg count
 * @argv: arg vector
 * Return: success
 */

int main(int argc, char *argv[])
{
	int change[] = {25, 10, 5, 2, 1};
	int a, b, x, y, result = 0;

	if (argc <= 1)
	{
		printf("Error\n");
		return (1);
	}

	y = atoi(argv[1]);

	if (y < 0)
		printf("0\n");
	else
	{
		for (x = 0; x < 5; x++)
		{
			a = y / change[x];
			b = y % change[x];
			result += a;
			y = b;
		}

		printf("%d\n", result);
	}

	exit(EXIT_SUCCESS);
}

