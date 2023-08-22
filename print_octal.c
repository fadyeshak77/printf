#include "main.h"

/**
 * print_octal - Print an unsigned number in octal format.
 * @args:    The variable argument list.
 * @params:  The formatting parameters.
 *
 * Return: The number of characters printed.
 */
int print_octal(va_list args, params_t *params)
{
	unsigned long octal_number;
	int total_printed_chars = 0;
	char *str;

	if (params->l_modifier)
		octal_number = (unsigned long) va_arg(args, unsigned long);
	else if (params->h_modifier)
		octal_number = (unsigned short int) va_arg(args, unsigned int);
	else
		octal_number = (unsigned int) va_arg(args, unsigned int);

	str = convert_num_to_string(octal_number, 8, CONVERT_TO_UNSIGNED, params);
	if (params->hashtag_flag && octal_number)
		*--str = '0';

	params->unsign = 1;
	return (total_printed_chars += print_number(str, params));
}
