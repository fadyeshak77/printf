#include "main.h"

/**
 * print_percent - Print a percent character with specified formatting.
 * @args:    The variable argument list.
 * @params:  The formatting parameters.
 *
 * Return: The number of characters printed.
 */
int print_percent(va_list args, params_t *params)
{
	IGNORE_PARAM(params);
	IGNORE_PARAM(args);
	return (_putchar('%'));
}
