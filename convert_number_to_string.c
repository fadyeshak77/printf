#include "main.h"

/**
 * convert_number_to_string - Convert a number to a string representation.
 * @num:    The number to convert.
 * @base:   The base for the conversion (e.g., 10 for decimal).
 * @flags:  Conversion flags.
 * @params: The formatting parameters (unused).
 *
 * Return: Pointer to the string representation of the number.
 */
char *convert_num_to_string(long int num, int base,
			int flags, params_t *params)
{
	static char buffer[50];
	char sign = 0;
	char *number_string = &buffer[49];
	unsigned long n = num;
	static char *array;

	IGNORE_PARAM(params);
	if (!(flags & CONVERT_TO_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}

	if (flags & CONVERT_TO_LOWERCASE)
		array = "0123456789abcdef";
	else
		array = "0123456789ABCDEF";

	*number_string = '\0';

	if (n == 0)
		*--number_string = '0';
	else
	{
		while (n != 0)
		{
			*--number_string = array[n % base];
			n /= base;
		}
	}

	if (sign)
		*--number_string = sign;

	return (number_string);
}
