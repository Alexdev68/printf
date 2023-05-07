#include "main.h"

/**
 * print_int - This prints an integer
 * @data: This is the data being passed into the function
 * Return: This function returns 0
 */
int print_int(va_list data)
{
	int num = va_arg(data, int);
	int k;
	char no[1024];
	int len = 0;
	int count = 0, sign;
	if (num == 0)
	{
		_putchar(0 + '0');
	}

	if (num < 0)
	{
		sign = 1;
		num = -(num);
	}
	k = 0;
	while (num > 0)
	{
		no[k] = (num % 10) + '0';
		num /= 10;
		k++;
		len++;
	}
	no[k] = '\0';

	if (sign == 1)
	{
		_putchar(- + '0');
		count++;
	}
	for (k = len - 1; k >= 0; k--)
	{
		_putchar(no[k]);
		count++;
	}
	return (count);
}

/**
 * print_char - This function prints a character
 * @data: This is the data passed into the function
 * Return: This return 0
 */
int print_char(va_list data)
{
	char let;
	int count = 0;

	let = va_arg(data, int);
	if (let == '\0')
	{
		return (-1);
	}

	_putchar(let);
	count++;
	return (count);
}

/**
 * print_string - This function prints a string
 * @data: This is the data passed into the function
 * Return: This returns 0
 */
int print_string(va_list data)
{
	char *str;
	int i, len;
	int count = 0;

	str = va_arg(data, char *);

	if (str == NULL)
	{
		_puts("(null)");
		return (-1);
	}

	len = strlen(str);

	for (i = 0; i < len; i++)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}

/**
 * print_percent - This function prints a character
 * @data: This is the data passed into the function
 * Return: This return 0
 */
int print_percent(va_list __attribute__((unused)) data)
{
	int count = 0;

	_putchar('%');
	count++;

	return (count);
}
