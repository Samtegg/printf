#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

/**
 * just_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: Width.
 */
int just_width(const char *format, int *i, va_list list)
{
    int width = 0;
    int curr_i = *i + 1; /* Start parsing from the next character after *i */

    while (format[curr_i] != '\0') {
        if (isdigit(format[curr_i])) {
            /* Accumulate digits to calculate the width */
            width = width * 10 + (format[curr_i] - '0');
        } else if (format[curr_i] == '*') {
            *i = curr_i;  /* Update the position before breaking the loop */
            width = va_arg(list, int); /* Get width from the variable argument list */
            break;
        } else {
            break; /* Exit the loop if a non-digit, non-asterisk character is encountered */
        }
        curr_i++;
    }

    *i = curr_i - 1;  /* Adjust the position after the loop */

    return width;
}

