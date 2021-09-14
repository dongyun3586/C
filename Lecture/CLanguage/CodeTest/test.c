#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STR_SIZE 100 

// countVowelConsonant( ) 함수 선언
void countVowelConsonant(char* str, int* vowel, int* consonant);
int isVowel(char ch);

void main()
{
    char str[STR_SIZE];
    int vowel = 0, consonant = 0;

    printf("문자열 안의 자음과 모음 개수 구하기\n");
    printf("문자열 입력 : ");
    fgets(str, sizeof str, stdin);

    // countVowelConsonant( ) 함수 호출
    countVowelConsonant(str, &vowel, &consonant);

    printf("문자열의 모음 개수 : %d\n", vowel);
    printf("문자열의 자음 개수 : %d\n\n", consonant);
}

// countVowelConsonant( ) 함수 정의
void countVowelConsonant(char* str, int* vowel, int* consonant) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isVowel(str[i]))
            (*vowel)++;
        else if(isalpha(str[i]))
            (*consonant)++;
    }
}

int isVowel(char ch) {
    char vowels[] = "aeiouAEIOU";
    for (int i = 0; i < 10; i++)
        if (ch == vowels[i])
            return 1;
    return 0;
}