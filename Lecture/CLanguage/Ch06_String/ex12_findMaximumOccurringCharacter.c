#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_SIZE 100        // 문자열 최대 길이
#define ASCII_SIZE 255      // 아스키 코드 길이

int maxFrequenceCharacter(char* str, int* ch_fre);

void main()
{
    char strArr[STR_SIZE];
    int asciiFrequencyArr[ASCII_SIZE] = { 0 };  // 해당 아스키 위치에 출현 빈도 저장
    int max;

    printf("문자열에서 가장 빈도수 높은 문자 찾기\n");
    printf("Input the string : ");
    fgets(strArr, sizeof(strArr), stdin);

    max = maxFrequenceCharacter(strArr, asciiFrequencyArr);

    printf("'%c'가 %d회로 가장 많이 나타남.\n", max, asciiFrequencyArr[max]);
}

int maxFrequenceCharacter(char* str, int* ch_fre) {
    int max = 0, ascii;

    for (int i = 0; str[i] != '\0'; i++) {
        ascii = (int)str[i];                // 문자를 ascii 코드값으로 변환
        ch_fre[ascii]++;
    }

    for (int i = 0; i < ASCII_SIZE; i++)
    {
        if (ch_fre[max] < ch_fre[i])
            max = i;
    }

    return max;
}