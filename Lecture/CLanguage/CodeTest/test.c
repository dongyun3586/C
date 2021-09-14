#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STR_SIZE 100 

// countVowelConsonant( ) �Լ� ����
void countVowelConsonant(char* str, int* vowel, int* consonant);
int isVowel(char ch);

void main()
{
    char str[STR_SIZE];
    int vowel = 0, consonant = 0;

    printf("���ڿ� ���� ������ ���� ���� ���ϱ�\n");
    printf("���ڿ� �Է� : ");
    fgets(str, sizeof str, stdin);

    // countVowelConsonant( ) �Լ� ȣ��
    countVowelConsonant(str, &vowel, &consonant);

    printf("���ڿ��� ���� ���� : %d\n", vowel);
    printf("���ڿ��� ���� ���� : %d\n\n", consonant);
}

// countVowelConsonant( ) �Լ� ����
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