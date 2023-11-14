#include "main.h"

/**
 * a - Prints the contents of the buffer if it exists
 * @b: Array of chars
 * @c: Index at which to add the next char, represents the length.
 */
void a(char b[], int *c);

/**
 * d - Printf function
 * @e: format.
 * Return: Printed chars.
 */
int d(const char *e, ...)
{
	int f, g = 0, i, j = 0;
	int k, l, m, o = 0;
	va_list p;
	char q[BUFF_SIZE];

	if (e == NULL)
		return (-1);

	va_start(p, e);

	for (i = 0; e && e[i] != '\0'; i++)
	{
		if (e[i] != '%')
		{
			q[o++] = e[i];
			if (o == BUFF_SIZE)
				a(q, &o);
			/* write(1, &e[i], 1); */  /* Reinstated the previously
						      commented-out line */
			j++;
		}
		else
		{
			a(q, &o);
			f = just_flags(e, &i);
			k = just_width(e, &i, p);
			l = just_precision(e, &i, p);
			m = just_size(e, &i);
			++i;
			g = just_another(e, &i, p, q, f, k, l, m);
			if (g == -1)
				return (-1);
			j += g;
		}
	}

	a(q, &o);

	va_end(p);

	return (j);
}

/**
 * a - Prints the contents of the buffer if it exists
 * @b: Array of chars
 * @c: Index at which to add the next char, represents the length.
 */
void a(char b[], int *c)
{
	if (*c > 0)
		write(1, &b[0], *c);

	*c = 0;
}
