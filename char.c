#include "main.h"

/**
 * print_char - Print a character with specified formatting.
 * @args:      The variable argument list.
 * @params:    The formatting parameters.
 *
 * Return: The number of characters printed.
 */
int print_char(va_list args, params_t *params)
{
	char padding_char = ' ';
	unsigned int padding = 1, total_printed_chars = 0,
	character = va_arg(args, int);

	if (params->minus_flag)
		total_printed_chars += _putchar(character);
	while (padding++ < params->width)
		total_printed_chars += _putchar(padding_char);
	if (!params->minus_flag)
		total_printed_chars += _putchar(character);

	return (total_printed_chars);
}
