#include "main.h"

void printChar(va_list pointer)
{
	write(1, va_arg(pointer, int));
}

int _printf(const char *format, ...);
{
	va_list pointer;
	unsigned int i = 0, j = 0;

	search list[] = {
		{"c", printChar},
		{"i", printInt},
		{"d", printDecimal},
		{"s", printString},
		{'\0', NULL}
	};
	while ((format) && (format[i] != '\0'))
	{
		if ((format[i] == '%') && (format[i - 1]) != '\\')
		{	
			i++;
			while (j < 4)
			{
				if (*list[j].type == format[i])
				{	
					list[j].function(pointer);
				}
				j++;
			}
		}
		else
			write(1, format[i], sizeof(char));
		i++;
	}
	va_end(pointer);
}
