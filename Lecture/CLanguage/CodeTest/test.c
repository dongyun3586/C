#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100 
// �� removeLeading( ) �Լ� [8��]



// �� removeTrailing( ) �Լ� [8��]



int main()
{
    char str[MAX_SIZE];
    printf("���ڿ� �Է�: ");
    gets(str);

    printf("�Էµ� ���ڿ�: '%s'\n", str);
    removeLeading(str);
    printf("���� ���� ����: '%s'\n", str);
    removeTrailing(str);
    printf("���� ���� ����: '%s'\n", str);
    return 0;
}