#include "main.h"

void printChar(va_list pointer)
{
	char c = va_arg(pointer, int);

	write(1, &c, sizeof(char));
}

void printInt(va_list pointer)
{
	printf("%s", pointer);
}

void printDecimal(va_list pointer)
{
	printf("%s", pointer);
}

void printString(va_list pointer)
{
	char *s = va_arg(pointer, char *);

	if (s == NULL)
		s = "(null)";
	write(1, s, strlen(s));
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
		{'\0', NULL}
	};

	va_start(pointer, format);

	while ((format) && (format[i] != '\0'))
	{
		if (format[i] == '%')
		{	
			if (i > 0)
				if (format[i - 1] == '\\')
				{
					write(1, &format[i], sizeof(char));
					continue;
				}
			i++;
			while (j < 4)
			{
				if (*list[j].type == format[i])
				{	
					found = 1;
					list[j].function(pointer);
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
			write(1, &format[i], sizeof(char));
		i++;
		length++;
		j = 0;
	}
	return (length);
	va_end(pointer);
}
