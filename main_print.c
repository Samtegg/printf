#include "main.h"

/**
 * _printf - this function behaves like printf
 * @format: this identifier searchs.
 * Return: it returns an integer
 */

int _printf(const char *format, ...)
{
	dmatch n[] = {
		{"%c", dprintf_charact}, {"%s", dprintf_str}, {"%%", print_percent}, {"%i", dprint_int}, {"%d", dprint_dec}
	};

	va_list dargs;
	int j = 0, dlen = 0;

	va_start(dargs, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:	
	while (format[j] != '\0')
	{
		int k = 4;
		while (k >= 0)
		{
			if (n[k].jd[0] == format[j] && n[j].jd[1]  == format[j + 1])
			{
				dlen = dlen + n[k].e(dargs);
				j = j + 2;
				goto Here;
			}
			k--;
		}
		_putchar(format[j]);
		j++;
		dlen++;

	}
	va_end(dargs);
	return(dlen);
}

