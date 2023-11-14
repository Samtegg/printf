#include "main.h"

/**
 * handle_print - just_print is responsible for displaying arguments
 * @fmt: The formatted string specifying how to present the arguments.
 * @ind: The index for tracking the current position.
 * @list: A collection of arguments to be output.
 * @buffer: An array serving as a buffer for handling the printing process.
 * @flags: A mechanism for determining active flags during printing.
 * @width: The width specifier for formatting.
 * @precision: Specification for precision during printing.
 * @size: A specifier indicating the size of the elements.
 *
 * Return: The count of characters printed, or -1 in case of an error.
 */
int just_another(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknown_len = 0;
	struct fmt_s
	{
		char fmt;
		int (*fn)(va_list, char *, int, int, int, int);
	};
	struct fmt_s fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}};

	for (i = 0; fmt_types[i].fmt && fmt[*ind] != fmt_types[i].fmt; i++)
		;

	if (!fmt_types[i].fmt)
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_len += write(1, &fmt[*ind], 1);
		return (unknown_len);
	}

	return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
}

