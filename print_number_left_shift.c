#include "main.h"

/**
 * print_number_left_shift - Print a number with
 * left shift and specified formatting.
 * @str:       The string representation of the number.
 * @format_params:    The formatting parameters.
 *
 * Return: The number of characters printed.
 */
int print_number_left_shift(char *str, params_t *format_params)
{
	unsigned int total_printed_chars = 0, padding_count = 0;
	char padding_char = ' ';

	if (format_params->zero_flag && !format_params->minus_flag)
		padding_char = '0';

	int is_negative = (!format_params->unsign && *str == '-');
	int original_neg = is_negative;

	if (is_negative && _strlen(str) < format_params->width &&
	padding_char == '0' && !format_params->minus_flag)
		str++;
	else
		is_negative = 0;

	if (format_params->plus_flag && !original_neg && !format_params->unsign)
	{
		total_printed_chars += _putchar('+');
		padding_count++;
	}
	else if (format_params->space_flag && !original_neg && !format_params->unsign)
	{
		total_printed_chars += _putchar(' ');
		padding_count++;
	}

	total_printed_chars += _puts(str);

	while (total_printed_chars++ < format_params->width)
		_putchar(padding_char);

	return (total_printed_chars);
}
