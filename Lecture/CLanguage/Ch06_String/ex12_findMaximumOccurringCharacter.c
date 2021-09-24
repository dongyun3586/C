#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_SIZE 100        // 문자열 최대 길이
#define ASCII_SIZE 128      // 아스키 코드 길이

int maxFrequenceCharacter(char* str, int* ch_fre);

void main()
{
    char strArr[STR_SIZE];
    int asciiFrequencyArr[ASCII_SIZE] = { 0 };
    int max;

    printf("문자열에서 가장 빈도수 높은 문자 찾기\n");
    printf("문자열 입력 : ");
    fgets(strArr, sizeof(strArr), stdin);

    max = maxFrequenceCharacter(strArr, asciiFrequencyArr);

    if (max != 0)
        printf("'%c'이/가 %d회로 가장 많이 나타남.\n", max, asciiFrequencyArr[max]);
    else
        printf("입력된 문자가 하나도 없습니다.\n");
}

int maxFrequenceCharacter(char* str, int* frequencyArr) {
    int max = 0, asciiCode;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n')
            continue;

        asciiCode = str[i];
        frequencyArr[asciiCode]++;
    }

    for (int i = 0; i < ASCII_SIZE; i++)
    {
        if (frequencyArr[max] < frequencyArr[i])
            max = i;
    }

    return max;
}