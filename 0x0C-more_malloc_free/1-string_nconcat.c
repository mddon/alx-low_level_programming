#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings.
 * @s1: the first string.
 * @s2: the second string.
 * @n: the amount of bytes.
 *
 * Return: pointer to the allocated memory.
 * if malloc fails, status value is equal to 98.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *sout;
	unsigned int is1, iis2, lsout, em;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (is1 = 0; s1[is1] != '\0'; is1++)
		;

	for (iis2 = 0; s2[iis2] != '\0'; iis2++)
		;

	if (n > iis2)
		n = iis2;

	lsout = is1 + n;

	sout = malloc(lsout + 1);

	if (sout == NULL)
		return (NULL);

	for (em = 0; em < lsout; em++)
		if (em < is1)
			sout[em] = s1[em];
		else
			sout[em] = s2[em - is1];

	sout[em] = '\0';

	return (sout);
}
