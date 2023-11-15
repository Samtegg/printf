#include "main.h"
/**
 * _dstrlen - this function returns the length of a string.
 * @dstr: this is the string pointer
 * Return: it returns j
 */
int _dstrlen(char *dstr)
{
	int j;

	for (j = 0; dstr[j] != 0; j++)
		;
	return (j);

}
/**
 * _dstrlenc - this is dstrlen but its applied for constant char pointer dstr
 * @dstr: this is the char pointer
 * Return: it returns j
 */
int _dstrlenc(const char *dstr)
{
	int j;

	for (j = 0; dstr[j] != 0; j++)
		;
	return (j);
}
