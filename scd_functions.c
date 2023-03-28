#include "main.h"

/**
 * print_unsigned - This function prints out an unsigned integer
 * @types: This is the list of arguments
 * @buffer: This is the buffer array
 * @flags: This is the active flags calculator
 * @width: This find the width
 * @precision: This is the precision specifier
 * @size: This is the size specifier
 * Return: This returns the number of characters printed out
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - This function prints out an unsigned number in octal notation
 * @types: This is the list of arg
 * @buffer: This is the buffer array
 * @flags: This is the active flags calculator
 * @width: This finds the width
 * @precision: This is the precision specifier
 * @size: This is the size specifier
 * Return: This returns the number of characters printed out
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - This function prints an unsigned number in hexadecimal
 * @types: This is the lists of arguments
 * @buffer: This is the buffer array
 * @flags: This is the active flags calculator
 * @width: This finds the width
 * @precision: This is the precision specifier
 * @size: This is the size specifier
 * Return: This returns the number of characters printed out
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - This prints an unsigned number in upper hexadecimal
 * @types: This is the list of arguments
 * @buffer: This is the buffer array
 * @flags: This is the active flags calculator
 * @width: This finds the width
 * @precision: This is the precision specifier
 * @size: This is the size specifier
 * Return: This returns the number of characters printed out
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**
 * print_hexa - This function prints an hexadecimal number in lower or upper
 * @types: This is the list of arguments
 * @map_to: This is an array of values to map
 * @buffer: This is the buffer array
 * @flags: This is the active flags calculator
 * @flag_ch: This calculates active flags characters
 * @width: This finds the width
 * @precision: This is the precision specifier
 * @size: This is the size specifier
 * Return: This returns the number of characters printed out
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
