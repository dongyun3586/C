#include <stdio.h>
#include <ctype.h>

char getStr(char* str);

int main()
{
    char str[100];

    while (getStr(str) != EOF) {
        if (isalpha(*str))
            printf("%s\n", str);
    }

    return 0;
}

char getStr(char* str) {
    char c;
    c = getchar();

    if (c != EOF) {
        *str = c;
        str++;
    }

    if (!isalpha(c))
        return c;

    while (1) {
        *str = getchar();
        if (!isalpha(*str))
            break;
        str++;
    }

    *str = '\0';
    return *str;
}