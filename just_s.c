#include "main.h"

/**
 * dprintf_str - this function prints out a string.
 * @valt: this is an argument.
 * Return: this returns the lenght of the string printed.
 */

int dprintf_str(va_list valt)
{
	char *dstr;
	int j;
	int dlength;

	dstr = va_arg(valt, char *);
	if (dstr == NULL)
	{
		dstr = "(null)";
		dlength = _dstrlen(dstr);
		for (j = 0; j < dlength; j++)
			_putchar(dstr[j]);
		return (dlength);

	}
	else
	{
		dlength = _dstrlen(dstr);
		for (j = 0; j < dlength; j++)
			_putchar(dstr[j]);
		return (dlength);

	}



}
