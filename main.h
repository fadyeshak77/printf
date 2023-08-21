#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define IGNORE_PARAM(x) (void)(x)
#define NULL_STRING_VALUE "(null)"
#define MAX_BUFFER_LENGTH 1024
#define RESET_OUTPUT_BUFFER -1
#define DEFAULT_PARAMETERS_VALUES {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_TO_LOWERCASE 1
#define CONVERT_TO_UNSIGNED 2

/**
 * struct parameters - Represents formatting parameters for printing.
 * @unsign:        Indicates if the value is unsigned.
 * @minus_flag:    Indicates left-justification of output.
 * @plus_flag:     Indicates whether to show plus sign for positive numbers.
 * @space_flag:    Indicates whether to prepend space for positive numbers.
 * @zero_flag:     Indicates zero-padding.
 * @hashtag_flag:  Indicates alternative form for certain conversions.
 * @width:         Minimum field width for output.
 * @precision:     Precision for floating-point conversions.
 * @l_modifier:    Long modifier for data types.
 * @h_modifier:    Short modifier for data types.
 */
typedef struct parameters
{
	unsigned int unsign : 1;
	unsigned int minus_flag : 1;
	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
} params_t;

/**
 * struct specifier - Represents a format specifier and
 * its corresponding function.
 * @specifier: The format specifier string.
 * @function:   Pointer to the function that handles the specifier.
 */
typedef struct specifier
{
	char *specifier;
	int (*function)(va_list, params_t *params);
} specifier_t;


/* Standard Output Functions */
int _puts(char *str);
int _putchar(int c);

/* Core Printing Functions */
int _printf(const char *format, ...);

/* Parameter Initialization */
void initialize_params(params_t *params, va_list args);

/* Character and String Printing */
int print_char(va_list args, params_t *params);
int print_string(va_list args, params_t *params);
int print_S(va_list args, params_t *params);

/* Numeric Printing Functions*/
int print_int(va_list args, params_t *params);
int print_unsigned(va_list args, params_t *params);

/* Special Printing Functions */
int print_memory_address(va_list args, params_t *params);
int print_percent(va_list args, params_t *params);

/* Numbering Systems Functions */
int print_binary(va_list args, params_t *params);
int print_octal(va_list args, params_t *params);
int print_hex(va_list args, params_t *params);
int print_HEX(va_list args, params_t *params);

/* Formatting Helpers */
char *convert_num_to_string(long int num,
	int base, int flags, params_t *params);
int get_flag(char *format, params_t *params);
int get_modifier_length(char *format, params_t *params);
char *get_width(char *format, params_t *params, va_list args);
char *get_precision(char *format, params_t *params, va_list args);
int (*get_specifier(char *format))(va_list args, params_t *params);
int get_printed_function(char *format, va_list args, params_t *params);

/* Additional Printing Features */
int print_from_to(char *start, char *end, char *except);
int print_reverse(va_list args, params_t *params);
int print_rot13(va_list args, params_t *params);

/* Utility Functions */
int is_digit(char c);
int _strlen(char *str);

/* Numeric Printing Helpers Functions*/
int print_number(char *num_str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

#endif
