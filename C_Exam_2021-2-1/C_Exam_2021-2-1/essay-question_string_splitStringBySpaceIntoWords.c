#include <stdio.h>
#include <string.h>

// ���ڿ��� �Է��ϸ� �ܾ�� �и��Ͽ� ���ڿ� �迭�� ����

int main()
{
    char str[100];
    char newString[10][10];
    int i, a = 0, b = 0;
    printf("���ڿ� �Է� : ");
    gets(str);

    for (i = 0; i <= (strlen(str)); i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            newString[a][b] = '\0';
            a++;        // ���� �ܾ�
            b = 0;      // ���� �ܾ ���� 0���� �ʱ�ȭ
        }
        else
        {
            newString[a][b] = str[i];
            b++;
        }
    }

    printf("�������� �и��� �ܾ��\n");
    for (i = 0; i < a; i++)
        printf("%s\n", newString[i]);
    return 0;
}