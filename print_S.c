#include "main.h"

/**
 * print_S - Print a string with special characters escaped using hexadecimal.
 * @args:    The variable argument list.
 * @params:  The formatting parameters.
 *
 * Return: The number of characters printed.
 */
int print_S(va_list args, params_t *params)
{
	char *str = va_arg(args, char *);
	char *hex;
	int total_printed_chars = 0;

	if ((int) !str)
		return (_puts(NULL_STRING_VALUE));

	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			total_printed_chars += _putchar('\\');
			total_printed_chars += _putchar('x');
			hex = convert_num_to_string(*str, 16, 0, params);
			if (!hex[1])
				total_printed_chars += _putchar('0');
			total_printed_chars += _puts(hex);
		}
		else
			total_printed_chars += _putchar(*str);
	}

	return (total_printed_chars);
}
