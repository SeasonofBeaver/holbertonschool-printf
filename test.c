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

int itos(int num, char *str)
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
