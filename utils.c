#include "main.h"

/**
 * is_printable - This function checks if a character is printable or not
 * @c: This the character to be checked
 * Return: This returns 1 if the character is printable or 0 if not
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - This function appends ascii in hexadecimal code
 * @buffer: This is the buffer array of characters
 * @i: This is the index to start iteration
 * @ascii_code: This is the ASCII Code
 * Return: This returns 3 Always
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - This checks if a character is a digit
 * @c: This is the character to be checked
 * Return: This returns 1 if the character is a digit or 0 if not
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - This function casts a number to the specified size
 * @num: This is the number to cast
 * @size: This is the number indicating the type to cast
 * Return: This returns the casted value of the number
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - This function cast a number to the specified size
 * @num: This is the number to cast
 * @size: This is the number indicating the type to cast
 * Return: This returns the casted value of a number
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
