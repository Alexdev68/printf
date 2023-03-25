#include "main.h"

/**
 * _putchar - This function prints a character at a time to the standard output
 * @c: This is the character being printed
 * Return: This returns the character to the standard output
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - This prints a string
 * @s: This is a pointer to the string
 * Return: This returns an integer value
 */
int _puts(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}
	return (i);
}

/**
 * _printf - This is a function that produces output according to a format
 * @format: This is a character string
 * Return: count
 */
int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					i += 2;
					break;
				case 's':
					count += _puts(va_arg(args, char *));
					i += 2;
					break;
				case '%':
					count += _putchar('%');
					i += 2;
					break;
				default:
					continue;
			}
		}
		count += _putchar(format[i]);
	}
	return (count);
	va_end(args);
}
