#include "main.h"

/**
 * print_string - Print a string with specified formatting.
 * @args:    The variable argument list.
 * @params:  The formatting parameters.
 *
 * Return: The number of characters printed.
 */
int print_string(va_list args, params_t *params)
{
	char *str = va_arg(args, char *);
	char padding_char = ' ';
	unsigned int padding = 0, total_printed_chars = 0, i = 0, j;

	IGNORE_PARAM(params);
	if ((int) !str)
		return (_puts(NULL_STRING_VALUE));

	j = padding = _strlen(str);
	if (params->precision < padding)
		j = padding = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < padding; i++)
				total_printed_chars += _putchar(*str++);
		else
			total_printed_chars += _puts(str);
	}

	while (j++ < params->width)
		total_printed_chars += _putchar(padding_char);

	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < padding; i++)
				total_printed_chars += _putchar(*str++);
		else
			total_printed_chars += _puts(str);
	}

	return (total_printed_chars);
}
