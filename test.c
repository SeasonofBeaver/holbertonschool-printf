#include "main.h"

void reverse(char *str, int len) {
    int s = 0;
    int e = len - 1;
    while (s < e) {
        char t = str[s];
        str[s] = str[e];
        str[e] = t;
        s++;
        e--;
    }
}

unsigned int itos(unsigned int num, char *str)
{
unsigned int i = 0, j;
unsigned int ineg = 0;

if (num == 0)
{
str[i++] = '0';
str[i] = '0';
return i;
}

/**
if (num < 0)
{
ineg = 1;
num = -num;
}
*/

while (num != 0)
{
j = num % 10;
str[i++] = j + '0';
num = num / 10;
}

if (ineg)
str[i++] = '-';

str[i] = '\0';

reverse(str, i);

return i;
}

int itosn(int num, char *str)
{
int i = 0, j;
int ineg = 0;

if (num == 0)
{
str[i++] = '0';
str[i] = '0';
return i;
}


if (num < 0)
{
ineg = 1;
num = -num;
}


while (num != 0)
{
j = num % 10;
str[i++] = j + '0';
num = num / 10;
}

if (ineg)
str[i++] = '-';

str[i] = '\0';

reverse(str, i);

return i;
}

int uitoso(unsigned int num, char *str)
{
	int i = 0, j;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (i);
	}

	while (num != 0)
	{
		j = num % 8;
		str[i++] = j + '0';
		num = num / 8;
	}

	str[i] = '\0';

	reverse(str, i);

	return (i);

}


int uitosh(unsigned int num, char *str, int uppercase)
{
	int i = 0, j;
	char hd[] = "0123456789abcdef";

	if (uppercase)
		strcpy(hd, "0123456789ABCDEF");

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (i);
	}

	while (num != 0) 
	{
		j = num % 16;
		str[i++] = hd[j];
		num = num / 16;
	}

	str[i] = '\0';

	reverse(str, i);
	return (i);
}
