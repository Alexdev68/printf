#include "main.h"

/**
 * find_flags - This function calculates the active flags
 * @format: This is the formatted string to print arguments
 * @i: This is a parameter assignment
 * Return: This returns the flags
 */
int find_flags(const char *format, int *i)
{
	int j, q;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (q = *i + 1; format[q] != '\0'; q++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[q] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
	}
	*i = q - 1;
	return (flags);
}
