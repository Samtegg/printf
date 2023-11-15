#include "main.h"

/**
 * _printf - this function behaves like printf
 * @dformat: this identifier searchs.
 * Return: it returns an integer
 */

int _printf(const char *dformat, ...)
{
	dmatch n[] = {
		{"%c", dprintf_charact}, {"%s", dprintf_str}, {"%%", print_percent}, {"%i", dprint_int}, {"%d", dprint_dec}
	};

	va_list dargs;
	int j = 0, dlen = 0;
	int k;

	va_start(dargs, dformat);
	if (dformat == NULL || (dformat[0] == '%' && dformat[1] == '\0'))
		return (-1);

Here:	
	while (dformat[j] != '\0')
	{
		int k = 4;
		while (k >= 0)
		{
			if (n[k].jd[0] == dformat[j] && n[j].jd[1]  == dformat[j + 1])
			{
				dlen = dlen + n[k].e(dargs);
				j = j + 2;
				goto Here;
			}
			k--;
		}
		_putchar(dformat[j]);
		j++;
		dlen++;

	}
	va_end(dargs);
	return(dlen);
}

