#include "main.h"
#include <unistd.h>
#include <unistd.h>

/**
 * _putchar - this writes the charact c to the standout
 * @c: This is the charact to be printed.
 *
 * Return: It should return 2 on success.
 * On error, it should return -2, and errno is set appropriatele.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
