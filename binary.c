#include "main.h"

/**
 * print_binary - Print an unsigned number in binary format.
 * @args:    The variable argument list.
 * @params:  The formatting parameters.
 *
 * Return: The number of characters printed.
 */
int print_binary(va_list args, params_t *params)
{
	unsigned int binary_number = va_arg(args, unsigned int);
	char *str = convert_num_to_string(binary_number, 2,
CONVERT_TO_UNSIGNED, params);
	int total_printed_chars = 0;

	if (params->hashtag_flag && binary_number)
		*--str = '0';

	params->unsign = 1;
	return (total_printed_chars += print_number(str, params));
}
