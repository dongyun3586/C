#include <stdio.h>

int main()
{
    char str1[10] = { 'H', 'e', 'l', 'l', 'o' };    // �迭�� ���ڿ� ����
    char str2[10] = "";                                 // �ι��ڷ� ���ڿ� �ʱ�ȭ
    char* sp = "Hello";                             // ������ ������ ���ڿ� ���� �ּ� ����
    int count_str1 = 0, count_str2 = 0;

    printf("%d, %d\n", sizeof(str1), sizeof(sp));

    // ���ڿ� �迭�� ���� ������ NUll ���ڷ� ä������.
    for (int i = 0; i < 10; i++) {
        printf("%c", str1[i]);
        if (str1[i] == '\0') count_str1++;
        if (str2[i] == '\0') count_str2++;
    }
    printf("%d %d\n", count_str1, count_str2);

    // ���ڿ� ���
    for (int i = 0; str1[i] != '\0'; i++)
        printf("%c\n", str1[i]);

    printf("%s %s\n", str1, sp);

    return 0;
}