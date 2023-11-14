#ifndef CUSTOM_PRINTF_H
#define CUSTOM_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1   /* Represents the left-align flag. */
#define F_PLUS 2    /* Represents the sign flag for positive numbers. */
#define F_ZERO 4    /* Represents the zero-fill flag. */
#define F_HASH 8    /* Represents the alternate form flag. */
#define F_SPACE 16  /* Represents the space flag for signed numbers. */

/* SIZES */
#define S_LONG 2    /* Represents the 'long' size specifier. */
#define S_SHORT 1   /* Represents the 'short' size specifier. */

/**
 * struct CustomFormat - Struct CustomFormat
 *
 * @fmt: The format specifier character.
 * @fn: The associated function for handling the format.
 */
struct CustomFormat
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct CustomFormat CustomFormat_t - Typedef for struct CustomFormat
 *
 * @fmt: The format specifier character.
 * @fm_t: The associated function for handling the format.
 */
typedef struct CustomFormat CustomFormat_t;

/* Function prototypes for custom_printf function and supporting functions */
int custom_printf(const char *format, ...);
int just_print(const char *fmt, int *i, va_list list, char buffer[],
				 int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print characters and strings */
int print_char(va_list types, char buffer[],
			   int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width,
				 int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width,
				  int precision, int size);

/* Functions to print numbers in various bases */
int print_int(va_list types, char buffer[], int flags, int width,
			  int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width,
				 int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width,
				   int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width,
				int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width,
					  int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width,
					 int precision, int size);

int print_hexa(va_list types, char map_to[], char buffer[],
			   int flags, char flag_ch, int width, int precision, int size);

/* Function to handle non-printable characters */
int print_non_printable(va_list types, char buffer[], int flags,
						int width, int precision, int size);

/* Function to print memory addresses */
int print_pointer(va_list types, char buffer[], int flags,
				   int width, int precision, int size);

/* Functions to handle other specifiers */
int just_flags(const char *format, int *i);
int just_width(const char *format, int *i, va_list list);
int just_precision(const char *format, int *i, va_list list);
int just_size(const char *format, int *i);

/* Function to print strings in reverse */
int print_reverse(va_list types, char buffer[], int flags, int width,
				  int precision, int size);

/* Function to print a string in ROT13 encoding */
int print_rot13string(va_list types, char buffer[], int flags,
					  int width, int precision, int size);

/* Handler for width formatting */
int handle_write_char(char c, char buffer[], int flags, int width,
					  int precision, int size);
int write_number(int is_positive, int ind, char buffer[], int flags,
				 int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
			  int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
				  int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind, char buffer[],
				 int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* CUSTOM_PRINTF_H */
