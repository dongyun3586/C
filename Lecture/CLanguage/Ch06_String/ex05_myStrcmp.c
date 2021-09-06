#include <stdio.h>
#define str_size 100 // 문자열 최대 길이

int checkEqualStr(char* s1, char* s2);

int main(void)
{
    char str1[str_size], str2[str_size];
    int flg = 0;
    printf("첫 번째 문자열 입력 : ");
    fgets(str1, sizeof str1, stdin);
    printf("두 번째 문자열 입력 : ");
    fgets(str2, sizeof str2, stdin);

    if (checkEqualStr(str1, str2) == 0)
        printf("\n같은 문자열 입니다.\n");
    else
        printf("\n다른 문자열 입니다.\n");

    return 0;
}

int checkEqualStr(char* s1, char* s2)
{
    while (*s1 != '\0' || *s2 != '\0') {
        if (*s1 == *s2) {
            s1++;
            s2++;
        }
        else if ((*s1 == '\0' && *s2 != '\0') || (*s1 != '\0' && *s2 == '\0') || *s1 != *s2) {
            return -1;
        }
    }
    return 0;
}