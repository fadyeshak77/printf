#include "main.h"

/**
 * print_int - Print a signed integer with specified formatting.
 * @args:    The variable argument list.
 * @params:  The formatting parameters.
 *
 * Return: The number of characters printed.
 */
int print_int(va_list args, params_t *params)
{
	long number;

	if (params->l_modifier)
		number = va_arg(args, long);
	else if (params->h_modifier)
		number = (short int) va_arg(args, int);
	else
		number = (int) va_arg(args, int);

	return (print_number(convert_num_to_string(number, 10, 0, params), params));
}
