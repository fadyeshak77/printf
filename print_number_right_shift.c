#include "main.h"

/**
 * print_number_right_shift - Print a number with
 * right shift and specified formatting.
 * @str:       The string representation of the number.
 * @params:    The formatting parameters.
 *
 * Return: The number of characters printed.
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int printed_chars = 0, pad_count = 0;
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	int is_neg = (!params->unsign && *str == '-');
	int orig_neg = is_neg;

	if (is_neg && _strlen(str) < params->width &&
	pad_char == '0' && !params->minus_flag)
		str++;
	else
		is_neg = 0;
	if ((params->plus_flag && !orig_neg) ||
	(!params->plus_flag && params->space_flag && !orig_neg))
		printed_chars++;
	if (is_neg && pad_char == '0')
		printed_chars += _putchar('-');
	if (params->plus_flag && !orig_neg && pad_char == '0' && !params->unsign)
		printed_chars += _putchar('+');
	else if (!params->plus_flag && params->space_flag &&
	!orig_neg && !params->unsign && params->zero_flag)
		printed_chars += _putchar(' ');
	while (printed_chars++ < params->width)
		_putchar(pad_char);
	if (is_neg && pad_char == ' ')
		printed_chars += _putchar('-');
	if (params->plus_flag && !orig_neg && pad_char == ' ' && !params->unsign)
		printed_chars += _putchar('+');
	else if (!params->plus_flag && params->space_flag &&
	!orig_neg && !params->unsign && params->zero_flag)
		printed_chars += _putchar(' ');
	printed_chars += _puts(str);
	return (printed_chars);
}
