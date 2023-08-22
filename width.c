#include "main.h"

/**
 * get_width - Get the width specifier from the format string.
 * @format: The format specifier string.
 * @params: The formatting parameters to be modified.
 * @args:   The variable argument list.
 *
 * Return: Pointer to the next character in the
 * format string after width specifier.
 */
char *get_width(char *format, params_t *params, va_list args)
{
	int width = 0;

	if (*format == '*')
	{
		width = va_arg(args, int);
		format++;
	}
	else
	{
		while (is_digit(*format))
		{
			width = width * 10 + (*format++ - '0');
		}
	}

	params->width = width;

	return (format);
}
