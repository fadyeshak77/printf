#include "main.h"

/**
 * print_unsigned - Print an unsigned integer.
 * @args:   The variable argument list.
 * @params: The formatting parameters.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(va_list args, params_t *params)
{
	unsigned long long_number;

	if (params->l_modifier)
		long_number = (unsigned long) va_arg(args, unsigned long);
	else if (params->h_modifier)
		long_number = (unsigned short int) va_arg(args, unsigned int);
	else
		long_number = (unsigned int) va_arg(args, unsigned int);

	params->unsign = 1;

	return (print_number(convert_num_to_string(long_number, 10,
CONVERT_TO_UNSIGNED, params), params));
}
