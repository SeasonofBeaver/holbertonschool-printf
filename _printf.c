#include "main.h"

int printChar(va_list pointer)
{
	char c = va_arg(pointer, int);

	write(1, &c, sizeof(char));
	return (1);

}

int printInt(va_list pointer)
{
	int i = va_arg(pointer, int);
	char b[50];
	int len = itosn(i, b);

	write(1, b, len);
	return (len);
}

int printDecimal(va_list pointer)
{
	int j = va_arg(pointer, int);
	char b[50];
	int len = itosn(j, b);

	write(1, b, len);
	return (len);
}

int printString(va_list pointer)
{
	char *s = va_arg(pointer, char *);

	if (s == NULL)
		s = "(null)";
	write(1, s, strlen(s));
	return (strlen(s));
}

int printUnsigned(va_list pointer)
{
	unsigned long int u = va_arg(pointer, unsigned long int);
	char b[50];
	int len = itos(u, b);

	write(1, b, len);
	return (len);
}

int printOctal(va_list pointer)
{
	unsigned int o = va_arg(pointer, unsigned int);
	char b[50];
	int len = uitoso(o, b);

	write(1, b, len);
	return (len);
}

int printHex(va_list pointer)
{
	unsigned int x = va_arg(pointer, unsigned int);
	char b[50];
	int len = uitosh(x, b, 0);

	write(1, b, len);
	return (len);
}

int printHexUpper(va_list pointer)
{
	unsigned int X = va_arg(pointer, unsigned int);
	char b[50];
	int len = uitosh(X, b, 1);

	write(1, b, len);
	return (len);
}

int printAddress(va_list pointer)
{
	unsigned long int p = va_arg(pointer, unsigned long int);
	char *add = "0x";

	write(1, add, 2);
	add = convert(p, 16, 1);
	write(1, add, strlen(add));

	return (strlen(add) + 2);
}
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
			return list[j].function(args);
		j++;
	}
	return 0;
}

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
			if (len)
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
