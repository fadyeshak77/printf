#include "main.h"

/**
 * initialize_params - Initializes formatting parameters.
 * @params: Pointer to the parameters struct to be initialized.
 * @args:   Variable argument list containing format specifiers (unused).
 */
void initialize_params(params_t *params, va_list args)
{
	params->unsign = 0;
	params->minus_flag = 0;
	params->plus_flag = 0;
	params->space_flag = 0;
	params->zero_flag = 0;
	params->hashtag_flag = 0;
	params->width = 0;
	params->precision = UINT_MAX;
	params->h_modifier = 0;
	params->l_modifier = 0;
	IGNORE_PARAM(args);
}
