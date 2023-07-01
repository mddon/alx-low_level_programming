#include "variadic_functions.h"

/**
 * print_numbers - This is to print numbers.
 * @separator: string to be printed between numbers.
 * @n: the number of integers passed to the function.
 *
 * Return: return nothing.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list valist;
	unsigned int a;

	va_start(valist, n);

	for (a = 0; a < n; a++)
	{
		printf("%d", va_arg(valist, int));
		if (separator && a < n - 1)
			printf("%s", separator);	}

	printf("\n");
	va_end(valist);
}
