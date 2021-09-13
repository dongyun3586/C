#include <stdio.h>
#include <string.h>
void main() {
    char str[150];
    int i, j;

    printf("Alphabet 이외의 문자 제거하기\n");
    printf("문자열 입력 : ");
    fgets(str, sizeof str, stdin);
    for (i = 0; str[i] != '\0'; ++i)
    {
        while (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z' || str[i] == '\0')))
        {
            for (j = i; str[j] != '\0'; ++j)
            {
                str[j] = str[j + 1];
            }
            str[j] = '\0';
        }
    }
    printf("최종 문자열 : %s\n", str);
}