#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 **argstostr -  a function that concatenates all the arguments of your program.
 *@ac : int
 *@av : array
 *Return: array
 */
char *argstostr(int ac, char **av)
{
	int a, b, x, y, i = 0, k = 0;
	char *s;

	if (ac == 0 || av == NULL)
	return (NULL);
	for (x = 0; (x < ac); x++)
	{
		for (y = 0; av[x][y] != '\0'; y++)
		i++;
		i++;
	}

	s = malloc(sizeof(char) * i + 1);
	if (s == NULL)
	return (NULL);
	for (a = 0; a < ac ; a++)
	{
		for (b = 0; av[a][b] != '\0'; b++)
		{
			s[k] = av[a][b];
			k++;
		}
		s[k++] = '\n';
	}
	s[k] = '\0';
	return (s);
}
