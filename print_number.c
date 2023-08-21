#include "main.h"

/**
 * print_number - Print a number with specified formatting.
 * @num_str: The string representation of the number.
 * @params:  The formatting parameters.
 *
 * Return: The number of characters printed.
 */
int print_number(char *num_str, params_t *params)
{
	unsigned int i = _strlen(num_str);
	int negative = (!params->unsign && *num_str == '-');

	if (!params->precision && *num_str == '0' && !num_str[1])
		num_str = "";
	if (negative)
	{
		num_str++;
		i--;
	}

	if (params->precision != UINT_MAX)
	{
		while (i++ < params->precision)
		{
			*--num_str = '0';
		}
	}
	if (negative)
		*--num_str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(num_str, params));
	else
		return (print_number_left_shift(num_str, params));
}
