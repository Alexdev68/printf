#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - This a function that works like the printf function
 * @format: This is the format character string
 * Return: This returns printed char
 */
int _printf(const char *format, ...)
{
	int i, outputted = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);

			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = find_flags(format, &i);
			width = find_width(format, &i, list);
			precision = find_precision(format, &i, list);
			size = find_size(format, &i);
			++i;
			outputted = handle_output(format, &i, list, buffer,
					flags, width, precision, size);
			if (outputted == -1)
				return (-1);
			printed_chars += outputted;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}

/**
 * print_buffer - This prints the contents of a buffer if they exist
 * @buffer: This is an array of chars
 * @buff_ind: This is the index to add the next char, length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
