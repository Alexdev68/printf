#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * struct op - This struct is used for function linking
 *
 * @sp: This is the specifier
 * @func: This is the function associated with the specifier
 */
typedef struct link
{
	char *sp;
	int (*func)(va_list);
}link_t;

int _printf(const char *format, ...);
int (*get_sp_func(char *s))(va_list);
int _putchar(char c);
int print_int(va_list data);
int print_string(va_list data);
int print_char(va_list data);
int print_percent(va_list data);
int _puts(char *s);

#endif
