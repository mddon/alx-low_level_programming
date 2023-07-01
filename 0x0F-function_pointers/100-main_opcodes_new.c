#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code for Holberton School students.
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *opc = (char *) main;
	int x, num_byte;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	num_byte = atoi(argv[1]);

	if (num_byte < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (x = 0; x < num_byte; x++)
	{
		printf("%02x", opc[x] & 0xFF);
		if (x != num_byte - 1)
			printf(" ");
	}

	printf("\n");
	return (0);
}
