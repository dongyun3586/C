#include <stdio.h>
#include <string.h>

// 문자열을 입력하면 단어별로 분리하여 문자열 배열에 저장

int main()
{
    char str[100];
    char newString[10][10];
    int i, a = 0, b = 0;
    printf("문자열 입력 : ");
    gets(str);

    for (i = 0; i <= (strlen(str)); i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            newString[a][b] = '\0';
            a++;        // 다음 단어
            b = 0;      // 다음 단어를 위해 0으로 초기화
        }
        else
        {
            newString[a][b] = str[i];
            b++;
        }
    }

    printf("공백으로 분리된 단어들\n");
    for (i = 0; i < a; i++)
        printf("%s\n", newString[i]);
    return 0;
}