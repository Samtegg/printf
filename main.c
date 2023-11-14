#include <limits.h>
#include <stdio.h>
#include <unistd.h>  /* Include this header for STDOUT_FILENO */
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = dprintf(STDOUT_FILENO, "Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    dprintf(STDOUT_FILENO, "Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    dprintf(STDOUT_FILENO, "Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    dprintf(STDOUT_FILENO, "Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    dprintf(STDOUT_FILENO, "Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    dprintf(STDOUT_FILENO, "Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    dprintf(STDOUT_FILENO, "Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    dprintf(STDOUT_FILENO, "String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    dprintf(STDOUT_FILENO, "Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = dprintf(STDOUT_FILENO, "Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    dprintf(STDOUT_FILENO, "Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    dprintf(STDOUT_FILENO, "Unknown:[%%r]\n");
    printf("Unknown:[%%r]\n");
    return (0);
}

