#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct format
{
	char *jd;
	int (*e)();
} dmatch;

int dprintf_charact(va_list valt);
int _putchar(char c);
int _printf(const char *format, ...);
int dprintf_str(va_list valt);
int _dstrlen(char *dstr);
int _dstrlenc(const char *dstr);
int print_percent(void);
int dprint_int(va_list dargs);
int dprint_dec(va_list dargs);

#endif
