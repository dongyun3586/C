#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    int words = 0;

    /* loop till end of string */
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            words++;
    }
    return words;
}