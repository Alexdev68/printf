#include "main.h"

/**
 * find_width - This function calculates the width to  be printed
 * @format: This is the formatted string in which to be printed
 * @i: This is the number of args to print
 * @list: This is the list of arg
 * Return: This function returns the width
 */
int find_width(const char *format, int *i, va_list list)
{
	int q;
	int width = 0;

	for (q = *i + 1; format[q] != '\0'; q++)
	{
		if (is_digit(format[q]))
		{
			width *= 10;
			width += format[q] - '0';
		}
		else if (format[q] == '*')
		{
			q++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = q - 1;
	return (width);
}
