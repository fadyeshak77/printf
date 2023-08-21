#include "main.h"

/**
 * _putchar - Writes a character to standard output.
 * @c: The character to be written.
 *
 * Return: On success, returns 1. On failure, returns -1.
 */
int _putchar(int c)
{
	static int buffer_index;
	static char output_buffer[MAX_BUFFER_LENGTH];

	if (c == RESET_OUTPUT_BUFFER || buffer_index >= MAX_BUFFER_LENGTH)
	{
		write(1, output_buffer, buffer_index);
		buffer_index = 0;
	}

	if (c != RESET_OUTPUT_BUFFER)
	{
		output_buffer[buffer_index++] = c;
	}

	return (1);
}

