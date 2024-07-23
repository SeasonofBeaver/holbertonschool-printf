#include "main.h"

int printChar(va_list pointer)
{
	char c = va_arg(pointer, int);

	write(1, &c, sizeof(char));
	return (0);
}

int printInt(va_list pointer)
{
	int i = va_arg(pointer, int);
	char b[50];
	int len = itosn(i, b);
	
	write(1, b, len);
	return (len - 1);
}

int printDecimal(va_list pointer)
{
	int j = va_arg(pointer, int);
	char b[50];
	int len = itosn(j, b);
	
	write(1, b, len);
	return (len - 1);
}

int printString(va_list pointer)
{
	char *s = va_arg(pointer, char *);

	if (s == NULL)
		s = "(null)";
	write(1, s, strlen(s));
	return (strlen(s) - 1);
}

int printUnsigned(va_list pointer)
{
	unsigned int u = va_arg(pointer, unsigned int);
	char b[50];
	int len = itos(u, b);
	write(1, b, len);
	return (len - 1);
}

int printOctal(va_list pointer)
{
	unsigned int o = va_arg(pointer, unsigned int);
	char b[50];
	int len = uitoso(o, b);
	write(1, b, len);
	return (len - 1);
}

int printHex(va_list pointer)
{
	unsigned int x = va_arg(pointer, unsigned int);
	char b[50];
	int len = uitosh(x, b, 0);
	write(1, b, len);
	return (len - 1);
}

int printHexUpper(va_list pointer)
{
	unsigned int X = va_arg(pointer, unsigned int);
	char b[50];
	int len = uitosh(X, b, 1);
	write(1, b, len);
	return (len - 1);
}

int _printf(const char *format, ...)
{
	va_list pointer;
	unsigned int i = 0, j = 0, length = 0, found = 0;

	search list[] = {
		{"c", printChar},
		{"i", printInt},
		{"d", printDecimal},
		{"s", printString},
		{"u", printUnsigned},
		{"o", printOctal},
		{"x", printHex},
		{"X", printHexUpper},
		{'\0', NULL}
	};

	va_start(pointer, format);

	while ((format) && (format[i] != '\0'))
	{
		if (format[i] == '%')
		{	
			if (format[i + 1] == '%')
			{
				i++;
				continue;
			}
			if (i > 0)
				if (format[i - 1] == '\\')
				{
					write(1, &format[i], sizeof(char));
					continue;
				}
			i++;
			while (j < 8)
			{
				if (*list[j].type == format[i])
				{	
					found = 1;
					length += list[j].function(pointer);
				}
				j++;
			}
			if (found == 0)
			{
				i--;
				write(1, &format[i], sizeof(char));
			}
			found = 0;
		}
		else
		{
			write(1, &format[i], sizeof(char));
		}
		i++;
		length++;
		j = 0;
	}
	return (length);
	va_end(pointer);
}
