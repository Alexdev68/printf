#include "main.h"

/**
 * handle_output - This function prints an argument
 * @fmt: This is the formatted string in which to print argument
 * @list: This is the list of arguments
 * @ind: This is an index
 * @buffer: This is the buffer array
 * @flags: This is the active flags calculator
 * @width: This procures the  width
 * @precision: This is the precision specifier
 * @size: This is the size specifier
 * Return: This function returns 1 or 2
 */
int handle_output(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	spec_z spec_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; spec_types[i].spec != '\0'; i++)
		if (fmt[*ind] == spec_types[i].spec)
			return (spec_types[i].func(list, buffer, flags, width, precision, size));

	if (spec_types[i].spec == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
