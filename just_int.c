#include "main.h"

/**
 * dprint_int - this functions prints interger.
 * @dargs: this is the arguement to print.
 * Return: this is the number of charact to be printed
 */
int dprint_int(va_list dargs)
{
	int m = va_arg(dargs, int);
	int dnum, dlast = m % 10, ddigit, dexp = 1;
	int j = 1;

	m = m / 10;
	dnum = m;

	if (dlast < 0)
	{
		_putchar('-');
		dnum = -dnum;
		m = -m;
		dlast = -dlast;
		j++;
	}
	if (dnum > 0)
	{
		while (dnum / 10 != 0)
		{
			dexp = dexp * 10;
			dnum = dnum / 10;
		}
		dnum = m;
		while (dexp > 0)
		{
			ddigit = dnum / dexp;
			_putchar(ddigit + '0');
			dnum = dnum - (ddigit * dexp);
			dexp = dexp / 10;
			j++;
		}
	}
	_putchar(dlast + '0');
	return(j);

}
#include "main.h"
#include "main.h"

/**
 * dprint_dec - this functions prints decimal.
 * @dargs: this is the arguement to print.
 * Return: this is the number of charact to be printed
 */
int dprint_dec(va_list dargs)
{
        int m = va_arg(dargs, int);
        int dnum, dlast = m % 10, ddigit, dexp = 1;
        int j = 1;

        m = m / 10;
        dnum = m;

        if (dlast < 0)
        {
                _putchar('-');
                dnum = -dnum;
                m = -m;
                dlast = -dlast;
                j++;
        }
        if (dnum > 0)
        {
                while (dnum / 10 != 0)
                {
                        dexp = dexp * 10;
                        dnum = dnum / 10;
                }
                dnum = m;
		while (dexp > 0)
                {
                        ddigit = dnum / dexp;
                        _putchar(ddigit + '0');
                        dnum = dnum - (ddigit * dexp);
                        dexp = dexp / 10;
                        j++;
                }
        }
        _putchar(dlast + '0');
        return(j);

}
