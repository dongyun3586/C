#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define str_size 100 

void main()
{
    char str[str_size];
    int vowel = 0, consonant = 0;

    printf("���ڿ� ���� ������ ���� ���� ���ϱ�\n");
    printf("���ڿ� �Է� : ");
    fgets(str, sizeof str, stdin);

    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            vowel++;
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            consonant++;
    }
    printf("���ڿ��� ���� ���� : %d\n", vowel);
    printf("���ڿ��� ���� ���� : %d\n\n", consonant);
}