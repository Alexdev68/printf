#include "main.h"

/**
 * _printf - This works like a printf function
 * @format: This is a character string
 * Return: This returns 0;
 */
int _printf(const char *format, ...)
{
	va_list data;
	int i = 0;
	int count = 0;
	char spec;

	va_start(data, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			spec = format[i + 1];
			count += get_sp_func(&spec)(data);
			i += 2;
		}
		else
		{
			_putchar(format[i]);
			i++;
			count++;
		}
	}
	va_end(data);
	return (count);
}
