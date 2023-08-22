#include "main.h"

/**
 * print_hex - Print an unsigned number in hexadecimal format.
 * @args:    The variable argument list.
 * @params:  The formatting parameters.
 *
 * Return: The number of characters printed.
 */
int print_hex(va_list args, params_t *params)
{
	unsigned long long_number;
	int total_printed_chars = 0;
	char *str;

	if (params->l_modifier)
		long_number = (unsigned long) va_arg(args, unsigned long);
	else if (params->h_modifier)
		long_number = (unsigned short int) va_arg(args, unsigned int);
	else
		long_number = (unsigned int) va_arg(args, unsigned int);

	str = convert_num_to_string(long_number, 16,
CONVERT_TO_UNSIGNED | CONVERT_TO_LOWERCASE, params);
	if (params->hashtag_flag && long_number)
	{
		*--str = 'x';
		*--str = '0';
	}

	params->unsign = 1;
	return (total_printed_chars += print_number(str, params));
}
