#include "main.h"

/**
 * convert - function
 *
 *@num: number
 *@base: base
 *@lowercase: specific case
 *
 * Return: Always 0
 */

char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep, b[50];
	char *ptr;

	if (lowercase)
		rep = "0123456789abcdef";
	else
		rep = "0123456789ABCDEF";
	ptr = &b[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);

}
