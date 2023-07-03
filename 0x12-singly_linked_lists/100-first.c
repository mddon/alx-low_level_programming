#include <stdio.h>

/**
 * bmain - this function will executed before the main
 * Return: it returns nothing.
 */

void __attribute__ ((constructor)) bmain()
{
	printf("You're beat! and yet, you must allow,");
	printf("\nI bore my house upon my back!\n");
}
