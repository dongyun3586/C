#include <stdio.h>

int main()
{
    int inputNum, decimalNum, binaryNum = 0;
    int r, p = 1;

    // �������� �Է¹ޱ�
    printf("������ �Է�: ");
    scanf("%d", &inputNum);
    decimalNum = inputNum;

    // 10���� -> 2���� ��ȯ
    // 1. while�� ���
    while (decimalNum > 0)
    {
        r = decimalNum % 2;
        binaryNum += (r * p);
        decimalNum /= 2;
        p *= 10;
    }

    printf("\nwhile�� ���\n");
    printf("10 ������ = %d\n", inputNum);
    printf(" 2 ������ = %d\n\n", binaryNum);

    binaryNum = 0;
    p = 1;
    // 2. for�� ���
    for (decimalNum = inputNum; decimalNum > 0; decimalNum /= 2) {
        r = decimalNum % 2;
        binaryNum += r * p;
        p *= 10;
    }

    printf("for�� ���\n");
    printf("10 ������ = %d\n", inputNum);
    printf(" 2 ������ = %d\n\n", binaryNum);

    return 0;
}