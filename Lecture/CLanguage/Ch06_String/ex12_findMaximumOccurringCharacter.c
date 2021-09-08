#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_SIZE 100        // ���ڿ� �ִ� ����
#define ASCII_SIZE 255      // �ƽ�Ű �ڵ� ����

int maxFrequenceCharacter(char* str, int* ch_fre);

void main()
{
    char strArr[STR_SIZE];
    int asciiFrequencyArr[ASCII_SIZE] = { 0 };  // �ش� �ƽ�Ű ��ġ�� ���� �� ����
    int max;

    printf("���ڿ����� ���� �󵵼� ���� ���� ã��\n");
    printf("Input the string : ");
    fgets(strArr, sizeof(strArr), stdin);

    max = maxFrequenceCharacter(strArr, asciiFrequencyArr);

    printf("'%c'�� %dȸ�� ���� ���� ��Ÿ��.\n", max, asciiFrequencyArr[max]);
}

int maxFrequenceCharacter(char* str, int* ch_fre) {
    int max = 0, ascii;

    for (int i = 0; str[i] != '\0'; i++) {
        ascii = (int)str[i];                // ���ڸ� ascii �ڵ尪���� ��ȯ
        ch_fre[ascii]++;
    }

    for (int i = 0; i < ASCII_SIZE; i++)
    {
        if (ch_fre[max] < ch_fre[i])
            max = i;
    }

    return max;
}