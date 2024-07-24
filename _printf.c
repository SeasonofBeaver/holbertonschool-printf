#include "main.h"

/**
 * printChar - Function
 *
 * @pointer: pointer to specific character in a list
 *
 * Return: length of 1 char
 */

int printChar(va_list pointer)
{
	char c = va_arg(pointer, int);

	write(1, &c, sizeof(char));
	return (1);

}

/**
 * printString - Function
 *
 * @pointer: pointer to specific character in a list
 *
 * Return: length of printed
 */

int printString(va_list pointer)
{
	char *s = va_arg(pointer, char *);

	if (s == NULL)
		s = "(null)";
	write(1, s, strlen(s));
	return (strlen(s));
}

/**
 * printAddress - Function
 *
 * @pointer: pointer to specific character in a list
 *
 * Return: length of printed, +2 because added 0x
 */

int printAddress(va_list pointer)
{
	unsigned long int p = va_arg(pointer, unsigned long int);
	char *add = "0x";

	write(1, add, 2);
	add = convert(p, 16, 1);
	write(1, add, strlen(add));

	return (strlen(add) + 2);
}

/**
 * handleFormat - Function
 *
 * @format: character in printed to compare with list
 * @args: output of what is to be printed instead of %?
 *
 * Return: length of printed or -1 if failed to print
 */

int handleFormat(const char format, va_list args)
{
	int j = 0;

	search list[] = {
		{'c', printChar},
		{'i', printInt},
		{'d', printDecimal},
		{'s', printString},
		{'u', printUnsigned},
		{'o', printOctal},
		{'x', printHex},
		{'X', printHexUpper},
		{'p', printAddress},
		{'\0', NULL}
	};
	while (j < 9)
	{
		if (format == list[j].type)
			return (list[j].function(args));
		j++;
	}
	return (-1);
}

/**
 * _printf - Function
 *
 * @format: to be printed + %? for inputs stored in ...
 *
 * Return: length of printed
 */

int _printf(const char *format, ...)
{
	va_list pointer;
	int i = 0, length = 0, len;

	if (!format || (format[i] == '%' && !format[1]))
		return (-1);
	va_start(pointer, format);
	while ((format) && (format[i] != '\0'))
	{
		if ((format[i] == '%') && (format[i + 1] == '%'))
		{
			write(1, &format[++i], sizeof(char));
			length++;
		}
		else if (format[i] == '%')
		{
			len = handleFormat(format[++i], pointer);
			if (len >= 0)
				length += len;
			else
			{
				i--;
				write(1, &format[i], sizeof(char));
				length++;
			}
		}
		else
		{
			write(1, &format[i], sizeof(char));
			length++;
		}
		i++;
	}
	va_end(pointer);
	return (length);
}
