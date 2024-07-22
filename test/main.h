#ifndef main_h
#define main_h

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...);
int itos(int num, char *str);
void reverse(char *str, int len);

struct formats
{
	char *type;
	void (*function)(va_list);
};

typedef struct formats search;

#endif /* main_h */
