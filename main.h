#ifndef main_h
#define main_h

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...);

unsigned int itos(unsigned long int num, char *str);
int itosn(int num, char *str);
void reverse(char *str, int len);
int uitoso(unsigned int num, char *str);
int uitosh(unsigned int num, char *str, int uppercase);
char *convert(unsigned long int num, int base, int lowercase);

/**
 * struct formats - structure
 *
 * @type: type
 * @function: function
 */


struct formats
{
	char *type;
	int (*function)(va_list);
};

typedef struct formats search;

#endif /* main_h */
