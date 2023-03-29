#include "main.h"

/**
 * find_precision - This funtion calculates the precision for printing
 * @format: This is the formatted str in which to print the arguments
 * @i: This is the number of args to print
 * @list: This is the list of args
 * Return: This function returns precision
 */
int find_precision(const char *format, int *i, va_list list)
{
	int q = *i + 1;
	int precision = -1;

	if (format[q] != '.')
		return (precision);

	precision = 0;

	for (q += 1; format[q] != '\0'; q++)
	{
		if (is_digit(format[q]))
		{
			precision *= 10;
			precision += format[q] - '0';
		}
		else if (format[q] == '*')
		{
			q++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = q - 1;
	return (precision);
}
