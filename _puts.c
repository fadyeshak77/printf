#include "main.h"

/**
 * _puts - Prints a string to standard output.
 * @str: The input string to be printed.
 *
 * Return: The number of characters printed.
 */
int _puts(char *str)
{
	int printed_chars = 0;

	for (char *current_char = str; *current_char; current_char++)
	{
		printed_chars += _putchar(*current_char);
	}
	return (printed_chars);
}
