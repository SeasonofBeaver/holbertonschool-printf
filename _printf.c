#include "main.h"

int printChar(va_list pointer)
{
	int len = 0;
	char c = va_arg(pointer, int);

	write(1, &c, sizeof(char));
	return (len);
}

int printInt(va_list pointer)
{
	int i = va_arg(pointer, int);
	char b[50];
	int len = itos(i, b);
	
	write(1, b, len);
	return (len - 1);
}

int printDecimal(va_list pointer)
{
	int d = va_arg(pointer, int);
	char b[50];
	int len = itos(d, b);
	
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

int printAddress(va_list pointer)
{
	unsigned long int p = va_arg(pointer, unsigned long int);
	char *add = "0x";

	write(1, add, 2); 
	add = convert(p, 16, 1);
	write(1, add, strlen(add));

	return (strlen(add) + 1);
}

int _printf(const char *format, ...)
{
	va_list pointer;
	int i = 0, j = 0, length = 0, found = 0;

	search list[] = {
		{"c", printChar},
		{"i", printInt},
		{"d", printDecimal},
		{"s", printString},
		{"p", printAddress},
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
				write(1, &format[i], sizeof(char));
				i++;
				length++;
				continue;
			}
			if (i > 0)
				if (format[i - 1] == '\\')
				{
					write(1, &format[i], sizeof(char));
					length++;
					continue;
				}
			i++;
			while (j < 5)
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
