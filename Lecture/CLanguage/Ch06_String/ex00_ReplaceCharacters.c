#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100];
    int length, ch;

    printf("��ҹ��� �ٲٱ�\n");
    printf("���ڿ� �Է� : ");
    fgets(str, sizeof str, stdin);

    length = strlen(str);
    printf("����� ���ڿ� : ");
    for (int i = 0; i < length; i++)
    {
        ch = islower(str[i]) ? toupper(str[i]) : tolower(str[i]);
        putchar(ch);
    }

    return 0;
}