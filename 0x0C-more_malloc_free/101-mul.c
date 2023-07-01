#include<string.h>
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * _isdigit - checks if character is digit
 * @ed: te character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int ed)
{
	return (ed >= '0' && ed <= '9');
}

/**
 * _strlen - returns the length of a string
 * @m: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *m)
{
	int i = 0;

	while (*m++)
		i++;
	return (i);
}

/**
 * big_multiply - multiply two big number strings
 * @s1: the first big number string
 * @s2: the second big number string
 *
 * Return: the product big number string
 */
char *big_multiply(char *s1, char *s2)
{
	char *y;
	int l1, l2, a, b, ed, x;

	l1 = _strlen(s1);
	l2 = _strlen(s2);
	y = malloc(a = x = l1 + l2);
	if (!y)
		printf("Error\n"), exit(98);
	while (a--)
		y[a] = 0;

	for (l1--; l1 >= 0; l1--)
	{
		if (!_isdigit(s1[l1]))
		{
			free(y);
			printf("Error\n"), exit(98);
		}
		a = s1[l1] - '0';
		ed = 0;

		for (l2 = _strlen(s2) - 1; l2 >= 0; l2--)
		{
			if (!_isdigit(s2[l2]))
			{
				free(y);
				printf("Error\n"), exit(98);
			}
			b = s2[l2] - '0';

			ed += y[l1 + l2 + 1] + (a * b);
			y[l1 + l2 + 1] = ed % 10;

			ed /= 10;
		}
		if (ed)
			y[l1 + l2 + 1] += ed;
	}
	return (y);
}


/**
 * main - multiply two big number strings
 * @argc: the number of arguments
 * @argv: the argument vector
 *
 * Return: Always 0 on success.
 */
int main(int argc, char **argv)
{
	char *y;
	int a, ed, x;

	if (argc != 3)
		printf("Error\n"), exit(98);

	x = _strlen(argv[1]) + _strlen(argv[2]);
	y = big_multiply(argv[1], argv[2]);
	ed = 0;
	a = 0;
	while (ed < x)
	{
		if (y[ed])
			a = 1;
		if (a)
			putchar(y[ed] + '0');
		ed++;
	}
	if (!a)
		putchar('0');
	putchar('\n');
	free(y);
	return (0);
}
