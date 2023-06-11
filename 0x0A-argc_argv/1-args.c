#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * @argc: arg count
 * @argc: arg vector
 * Return: success
 */

int main(int argc, char *argv[])
{
	(void)argv;
	printf("%d\n", argc -1);
	exit(EXIT_SUCCESS);
}
