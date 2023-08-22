#include "main.h"

/**
 * print_rot13 - Print a string using ROT13 encryption.
 * @args:   The variable argument list.
 * @params: The formatting parameters (unused).
 *
 * Return: The number of characters printed.
 */
int print_rot13(va_list args, params_t *params)
{
	int i = 0;
	int printed_chars = 0;
	char *str = va_arg(args, char *);

	IGNORE_PARAM(params);
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'M')
		    || (str[i] >= 'a' && str[i] <= 'm'))
		{
			printed_chars += _putchar(str[i] + 13);
		}
		else if ((str[i] >= 'N' && str[i] <= 'Z')
		|| (str[i] >= 'n' && str[i] <= 'z'))
		{
			printed_chars += _putchar(str[i] - 13);
		}
		else
		{
			printed_chars += _putchar(str[i]);
		}
		i++;
	}

	return (printed_chars);
}
