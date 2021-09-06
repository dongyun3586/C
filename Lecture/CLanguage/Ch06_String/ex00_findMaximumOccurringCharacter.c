#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define str_size 100    // ���ڿ� �ִ� ����
#define chr_no 255      // �ƽ�Ű �ڵ� ����

void main()
{
    char str[str_size];
    int ch_fre[chr_no] = { 0 };
    int i = 0, max;
    int ascii;

    printf("���ڿ����� ���� �󵵼� ���� ���� ã��\n");
    printf("Input the string : ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        ascii = (int)str[i];    // ���ڸ� ascii �ڵ尪���� ��ȯ
        ch_fre[ascii] += 1;     // �ش� �ƽ�Ű ��ġ�� ���� �� ����
    }

    max = 0;
    for (int i = 0; i < chr_no; i++)
    {
        if (ch_fre[i] > ch_fre[max])
            max = i;
    }
    printf("'%c'�� %dȸ�� ���� ���� ��Ÿ��.\n", max, ch_fre[max]);
}