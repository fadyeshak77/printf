#include "main.h"

/**
 * get_precision - Get the precision specifier from the format string.
 * @format: The format specifier string.
 * @params: The formatting parameters to be modified.
 * @args:   The variable argument list.
 *
 * Return: Pointer to the next character
 * in the format string after precision specifier.
 */
char *get_precision(char *format, params_t *params, va_list args)
{
	int precision = 0;

	if (*format != '.')
		return (format);

	format++;
	if (*format == '*')
	{
		precision = va_arg(args, int);
		format++;
	}
	else
	{
		while (is_digit(*format))
		{
			precision = precision * 10 + (*format++ - '0');
		}
	}

	params->precision = precision;
	return (format);
}

