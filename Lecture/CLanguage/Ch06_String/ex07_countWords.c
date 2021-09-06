#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countWords(char* str);

void main()
{
    char str[100];

    printf("문자열의 단어 숫자 세기\n");
    printf("------------------------------------------------------\n");
    printf("문자열 입력 : ");
    fgets(str, sizeof str, stdin);

    printf("총 단어 개수 : %d\n", countWords(str));
}

int countWords(char* str) {
    int words = 0;

    /* loop till end of string */
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            words++;
    }
    return words;
}