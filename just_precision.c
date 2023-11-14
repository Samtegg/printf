#include "main.h"

/**
 * just_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @index: List of arguments to be printed.
 * @args_list: List of arguments.
 *
 * Return: Precision.
 */
int just_precision(const char *format, int *index, va_list args_list)
{
    int current_index = *index + 1;
    int precision = -1;

    if (format[current_index] == '.')
    {
        precision = 0;

        while (format[++current_index] != '\0')
        {
            if (is_digit(format[current_index]))
            {
                precision = precision * 10 + (format[current_index] - '0');
            }
            else if (format[current_index] == '*')
            {
                current_index++;
                precision = va_arg(args_list, int);
                break;
            }
            else
            {
                break;
            }
        }
    }

    *index = current_index - 1;
    return precision;
}

