#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_SIZE 100        // ���ڿ� �ִ� ����
#define ASCII_SIZE 128      // �ƽ�Ű �ڵ� ����

int maxFrequenceCharacter(char* str, int* ch_fre);

void main()
{
    char strArr[STR_SIZE];
    int asciiFrequencyArr[ASCII_SIZE] = { 0 };
    int max;

    printf("���ڿ����� ���� �󵵼� ���� ���� ã��\n");
    printf("���ڿ� �Է� : ");
    fgets(strArr, sizeof(strArr), stdin);

    max = maxFrequenceCharacter(strArr, asciiFrequencyArr);

    if (max != 0)
        printf("'%c'��/�� %dȸ�� ���� ���� ��Ÿ��.\n", max, asciiFrequencyArr[max]);
    else
        printf("�Էµ� ���ڰ� �ϳ��� �����ϴ�.\n");
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