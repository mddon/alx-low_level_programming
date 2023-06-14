#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the addition of positive numbers
 * @argc: arg count
 * @argv: arg vector
 * Return: success
 */
int main(int argc, char *argv[])
{
	int a, k, sum = 0;

	for (a = 1; a < argc; a++)
	{
		for (k = 0; argv[a][k]; k++)
		{
			if (argv[a][k] < '0' || argv[a][k] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}
		sum += atoi(argv[a]);
	}
	printf("%d\n", sum);
	return (0);
}
