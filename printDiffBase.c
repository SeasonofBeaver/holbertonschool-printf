#include "main.h"

/**
 * printOctal - Function
 *
 * @pointer: pointer to specific character in list
 *
 * Return: length of printed
 */

int printOctal(va_list pointer)
{
	unsigned int o = va_arg(pointer, unsigned int);
	char b[50];
	int len = uitoso(o, b);

	write(1, b, len);
	return (len);
}

/**
 * printHex - Function
 *
 * @pointer: pointer to specific character in list
 *
 * Return: length of printed
 */

int printHex(va_list pointer)
{
	unsigned int x = va_arg(pointer, unsigned int);
	char b[50];
	int len = uitosh(x, b, 0);

	write(1, b, len);
	return (len);
}

/**
 * printHexUpper - Function
 *
 * @pointer: pointer to specific character in list
 *
 * Return: length of printed
 */

int printHexUpper(va_list pointer)
{
	unsigned int X = va_arg(pointer, unsigned int);
	char b[50];
	int len = uitosh(X, b, 1);

	write(1, b, len);
	return (len);
}
