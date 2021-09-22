#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countWords(char* str);

void main()
{
    char str[100];

    printf("���ڿ��� �ܾ� ���� ����\n");
    printf("------------------------------------------------------\n");
    printf("���ڿ� �Է� : ");
    fgets(str, sizeof str, stdin);

    printf("�� �ܾ� ���� : %d\n", countWords(str));
}

int countWords(char* str) {
    int wordCount = 0, isNewWord = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if (isNewWord) {
                wordCount++;
                isNewWord = 0;
            }
        }
        else {
            isNewWord = 1;
        }
    }

    return wordCount;
}