#include <stdio.h>
#include <unistd.h>
/**
 * main - Entry point
 * Description: prints lowercase alphabets
 * Return: Always 0 (success)
 */
int main(void)
{
	int ii;

	for (ii = 'a'; ii <= 'z'; ii++)
	{
		if (ii != 'e' && ii != 'q')
		{
			putchar(ii);
		}
		else
		{
		}
	}
	putchar('\n');
	return (0);
}
