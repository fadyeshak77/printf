#include "main.h"

/**
 * get_modifier_length - Get the length modifier from the format string.
 * @format: The format specifier character.
 * @params: The formatting parameters to be modified.
 *
 * Return: 1 if a length modifier was set, otherwise 0.
 */
int get_modifier_length(char *format, params_t *params)
{
	int modifier_length = 0;

	switch (*format)
	{
		case 'l':
			modifier_length = params->l_modifier = 1;
			break;
		case 'h':
			modifier_length = params->h_modifier = 1;
			break;
	}

	return (modifier_length);
}
