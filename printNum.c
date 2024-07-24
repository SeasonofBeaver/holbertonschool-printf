#include "main.h"

/**
 * printInt - Function
 *
 * @pointer: pointer to specific character in a list
 *
 * Return: length of printed
 */

int printInt(va_list pointer)
{
	int i = va_arg(pointer, int);
	char b[50];
	int len = itosn(i, b);

	write(1, b, len);
	return (len);
}

/**
 * printDecimal - Function
 *
 * @pointer: pointer to specific character in a list
 *
 * Return: length of printed
 */

int printDecimal(va_list pointer)
{
	int j = va_arg(pointer, int);
	char b[50];
	int len = itosn(j, b);

	write(1, b, len);
	return (len);
}

/**
 * printUnsigned - Function
 *
 * @pointer: pointer to specific character in a list
 *
 * Return: length of printed
 */

int printUnsigned(va_list pointer)
{
	unsigned long int u = va_arg(pointer, unsigned long int);
	char b[50];
	int len = itos(u, b);

	write(1, b, len);
	return (len);
}
