#include "main.h"

/**
 * get_printed_function - Get the appropriate printed
 * function based on format specifier.
 * @format: The format specifier character.
 * @args:   The variable argument list.
 * @params: The formatting parameters.
 *
 * Return: The result of the selected printed function, or 0 if not found.
 */
int get_printed_function(char *format, va_list args, params_t *params)
{
	int (*selected_function)(va_list, params_t*) = get_specifier(format);

	if (selected_function)
		return (selected_function(args, params));
	return (0);
}
