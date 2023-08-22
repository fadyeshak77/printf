#include "main.h"

/**
 * _printf - Custom implementation of printf function.
 * @format: The format string containing the desired output format.
 * @...: Additional arguments for formatting.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	int total_printed_chars = 0;
	char *current_char, *start_specifier;
	va_list args;
	params_t params = DEFAULT_PARAMETERS_VALUES;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (current_char = (char *) format; *current_char; current_char++)
	{
		initialize_params(&params, args);
		if (*current_char != '%')
		{
			total_printed_chars += _putchar(*current_char);
			continue;
		}
		start_specifier = current_char;
		current_char++;
		while (get_flag(current_char, &params))
			current_char++;
		current_char = get_width(current_char, &params, args);
		current_char = get_precision(current_char, &params, args);
		if (get_modifier_length(current_char, &params))
			current_char++;
		if (!get_specifier(current_char))
			total_printed_chars += print_from_to(start_specifier, current_char,
					 params.l_modifier || params.h_modifier ? current_char - 1 : 0);
		else
			total_printed_chars += get_printed_function(current_char, args, &params);
	}
	_putchar(RESET_OUTPUT_BUFFER);
	va_end(args);
	return (total_printed_chars);
}
