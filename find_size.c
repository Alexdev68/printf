#include "main.h"

/**
 * find_size - This function calculates the size to cast asign
 * @format: This is the formatted string to print arguments
 * @i: This is the number of arguments to print
 * Return: This function returns the size
 */
int find_size(const char *format, int *i)
{
	int q = *i + 1;
	int size = 0;

	if (format[q] == 'l')
		size = S_LONG;
	else if (format[q] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = q - 1;
	else
		*i = q;
	return (size);
}
