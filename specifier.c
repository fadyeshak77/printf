#include "main.h"

/**
 * get_specifier - Get the appropriate specifier function.
 * @format: The format specifier character.
 *
 * Return: Pointer to the matching specifier function, or NULL if not found.
 */

int (*get_specifier(char *format))(va_list args, params_t *params)
{
	specifier_t specifier[] = {
			{ "c", print_char },
			{ "d", print_int },
			{ "i", print_int },
			{ "s", print_string },
			{ "%", print_percent },
			{ "b", print_binary },
			{ "o", print_octal },
			{ "u", print_unsigned },
			{ "x", print_hex },
			{ "X", print_HEX },
			{ "p", print_memory_address },
			{ "S", print_S },
			{ "r", print_reverse },
			{ "R", print_rot13 },
			{ NULL, NULL }
	};
	int index = 0;

	while (specifier[index].specifier)
	{
		if (*format == specifier[index].specifier[0])
		{
			return (specifier[index].function);
		}
		index++;
	}

	return (NULL);
}
