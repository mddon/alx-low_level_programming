#include "main.h"
#include <stdlib.h>

/**
 * *str_concat - concatenates two strings
 * @s1: string to concatenate
 * @s2: other string to concatenate
 *
 * Return: pointer to the new string created (Success), or NULL (Error)
 */
char *str_concat(char *s1, char *s2)
{
	char *s3;
	unsigned int k1 = 0, k2 = 0, len1 = 0, len2 = 0;

	while (s1 && s1[len1])
		len1++;
	while (s2 && s2[len2])
		len2++;

	s3 = malloc(sizeof(char) * (len1 + len2 + 1));
	if (s3 == NULL)
		return (NULL);

	k1 = 0;
	k2 = 0;

	if (s1)
	{
		while (k1 < len1)
		{
			s3[k1] = s1[k1];
			k1++;
		}
	}

	if (s2)
	{
		while (k1 < (len1 + len2))
		{
			s3[k1] = s2[k2];
			k1++;
			k2++;
		}
	}
	s3[k1] = '\0';

	return (s3);
}
