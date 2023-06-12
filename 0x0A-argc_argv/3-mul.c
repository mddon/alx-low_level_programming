#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: success
 */

int main(int argc, char *argv[])
{
	int a = 1, b;
	if(argc == 3)
	{
		for (b = 1; b < argc; b++)
			a = a * strtol(argv[b], NULL, 10);
		printf("%d\n", a);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
