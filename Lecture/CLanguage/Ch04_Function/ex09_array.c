#include <stdio.h>

int main()
{
    int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };

    printf("%d\n", sizeof(numArr[0]));              // �迭 ��� �ϳ��� ũ��(byte)
    printf("%d\n", sizeof(numArr));                 // �迭�� ũ��(byte)
    printf("%d\n", sizeof(numArr) / sizeof(int));   // �迭�� ��� ����

    // �迭�� ��Ҹ� ��� ���
    for (int i = 0; i < 10; i++)
        printf("numArr[%d] = %d\n", i, numArr[i]);

    return 0;
}