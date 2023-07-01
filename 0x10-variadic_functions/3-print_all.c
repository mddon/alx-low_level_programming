#include "variadic_functions.h"

/**
 * print_all - prints everything.
 * @format: a list of types of arguments that is passed to the function.
 *
 * Return: return nothing.
 */
void print_all(const char * const format, ...)
{
	va_list valist;
	unsigned int i = 0, x, r = 0;
	char *str;
	const char t_arg[] = "cifs";

	va_start(valist, format);
	while (format && format[i])
	{
		x = 0;
		while (t_arg[x])
		{
			if (format[i] == t_arg[x] && r)
			{
				printf(", ");
				break;
			} x++;
		}
		switch (format[i])
		{
		case 'c':
			printf("%c", va_arg(valist, int)), r = 1;
			break;
		case 'i':
			printf("%d", va_arg(valist, int)), r = 1;
			break;
		case 'f':
			printf("%f", va_arg(valist, double)), r = 1;
			break;
		case 's':
			str = va_arg(valist, char *), r = 1;
			if (!str)
			{
				printf("(nil)");
				break;
			}
			printf("%s", str);
			break;
		} i++;
	}
	printf("\n"), va_end(valist);
}
