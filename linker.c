#include "main.h"

/**
 * *get_sp_func - This function gets the function associated with the specifier
 * @s: The is the character passed into the function to find the specifier
 * Return: This returns a pointer to the function associated with the specifier
 */
int (*get_sp_func(char *s))(va_list)
{
	int i;
	link_t specifiers[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{"%", print_percent},
		{'\0', NULL}
	};

	i = 0;
	while (i < 4)
	{
		if (s[0] == *specifiers[i].sp)
		{
			break;
		}
		i++;
	}

	return (specifiers[i].func);
}
