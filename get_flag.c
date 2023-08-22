#include "main.h"

/**
 * get_flag - Set the appropriate flag based on format specifier.
 * @format: The format specifier character.
 * @params: The formatting parameters to be modified.
 *
 * Return: 1 if a flag was set, otherwise 0.
 */
int get_flag(char *format, params_t *params)
{
	int flag_set = 0;

	switch (*format)
	{
		case '-':
			flag_set = params->minus_flag = 1;
			break;
		case '+':
			flag_set = params->plus_flag = 1;
			break;
		case ' ':
			flag_set = params->space_flag = 1;
			break;
		case '0':
			flag_set = params->zero_flag = 1;
			break;
		case '#':
			flag_set = params->hashtag_flag = 1;
			break;
	}

	return (flag_set);
}
