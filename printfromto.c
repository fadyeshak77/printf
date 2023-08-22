#include "main.h"

/**
 * print_from_to - Print characters from start to end, excluding except.
 * @start:  Pointer to the starting character.
 * @end:    Pointer to the ending character.
 * @except: Pointer to the character to be excluded.
 *
 * Return: The number of characters printed.
 */
int print_from_to(char *start, char *end, char *except)
{
	int total_printed_chars = 0;

	while (start <= end)
	{
		if (start != except)
		{
			total_printed_chars += _putchar(*start);
		}
		start++;
	}

	return (total_printed_chars);
}
