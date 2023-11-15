#include "main.h"

/**
 * dprintf_charact - this functions prints a character.
 * @valt: this is an arguments.
 * Return: 2.
 */
int dprintf_charact(va_list valt)
{
	char dstr;

	dstr = va_arg(valt, int);
	_putchar(dstr);
	return (2);

}
