#include <stdio.h>
#include <string.h>

void charPermu(char* str, int length)
{
    for (int i = 0; i < length; i++)
        for (int j = 0; j < length; j++) {
            if (i == j)
                continue;
            for (int k = 0; k < length; k++) {
                if (k == i || k == j)
                    continue;
                printf("%c%c%c ", str[i], str[j], str[k]);
            }
        }
}

int main()
{
    char* str = "abc";
    charPermu(str, strlen(str));
    return 0;
}