#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    int length, ch;

    printf("대소문자 바꾸기\n");
    printf("문자열 입력 : ");
    fgets(str, sizeof str, stdin);

    length = strlen(str);
    printf("변경된 문자열 : ");
    for (int i = 0; i < length; i++)
    {
        ch = islower(str[i]) ? toupper(str[i]) : tolower(str[i]);
        putchar(ch);
    }

    return 0;
}