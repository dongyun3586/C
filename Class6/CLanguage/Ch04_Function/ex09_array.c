#include <stdio.h>

int main()
{
    int numArr[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 1, 2, 3 };
    int arrCount = sizeof(numArr) / sizeof(numArr[0]);

    // 1. �迭�� ��� ��� ����ϱ�
    printf("1. �迭�� ��� ��� ����ϱ�\n");
    for (int i = 0; i < arrCount; i++)
        printf("numArr[%d] = %d\n", i, numArr[i]);
    printf("\n\n");

    // 2. �迭�� ��Ҹ� �������� ����ϱ�
    printf("2. �迭�� ��Ҹ� �������� ����ϱ�\n");
    // ���⿡ �ڵ� �ۼ�
    printf("\n\n");

    // 3. �迭�� ��� �հ� ���ϱ�
    printf("3. �迭�� ��� �հ� ���ϱ�\n");
    // ���⿡ �ڵ� �ۼ�
    printf("\n\n");

    return 0;
}