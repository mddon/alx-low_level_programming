#include "main.h"
#include <stdlib.h>


/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
	int flag, x, k;

	flag = 0;
	k = 0;

	for (x = 0; s[x] != '\0'; x++)
	{
		if (s[x] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			k++;
		}
	}

	return (k);
}
/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **alpha, *tmp;
	int a, b = 0, len = 0, words, z = 0, start, end;

	while (*(str + len))
		len++;
	words = count_word(str);
	if (words == 0)
		return (NULL);

	alpha = (char **) malloc(sizeof(char *) * (words + 1));
	if (alpha == NULL)
		return (NULL);

	for (a = 0; a <= len; a++)
	{
		if (str[a] == ' ' || str[a] == '\0')
		{
			if (z)
			{
				end = a;
				tmp = (char *) malloc(sizeof(char) * (z + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				alpha[b] = tmp - z;
				b++;
				z = 0;
			}
		}
		else if (z++ == 0)
			start = a;
	}

	alpha[b] = NULL;

	return (alpha);
}

