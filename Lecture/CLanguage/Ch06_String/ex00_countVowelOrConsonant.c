#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define str_size 100 

void main()
{
    char str[str_size];
    int vowel = 0, consonant = 0;

    printf("문자열 안의 자음과 모음 개수 구하기\n");
    printf("문자열 입력 : ");
    fgets(str, sizeof str, stdin);

    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            vowel++;
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            consonant++;
    }
    printf("문자열의 모음 개수 : %d\n", vowel);
    printf("문자열의 자음 개수 : %d\n\n", consonant);
}