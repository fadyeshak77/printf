#include "main.h"

/**
 * print_reverse - Print a string in reverse order.
 * @args:   The variable argument list.
 * @params: The formatting parameters (unused).
 *
 * Return: The number of characters printed.
 */
int print_reverse(va_list args, params_t *params)
{
	int total_printed_chars = 0, len = 0;
	char *str = va_arg(args, char *);

	IGNORE_PARAM(params);
	if (!str)
		return (0);

	while (*str)
	{
		len++;
		str++;
	}
	str--;

	for (; len > 0; len--, str--)
		total_printed_chars += _putchar(*str);

	return (total_printed_chars);
}
