#include "main.h"

/**
 * print_memory_address - Print a memory address in hexadecimal format.
 * @args:    The variable argument list.
 * @params:  The formatting parameters.
 *
 * Return: The number of characters printed.
 */
int print_memory_address(va_list args, params_t *params)
{
	unsigned long int number = va_arg(args, unsigned long int);
	char *address;

	if (!number)
		return (_puts("(nil)"));

	address = convert_num_to_string(number, 16,
CONVERT_TO_UNSIGNED | CONVERT_TO_LOWERCASE, params);
	*--address = 'x';
	*--address = '0';

	return (print_number(address, params));
}
