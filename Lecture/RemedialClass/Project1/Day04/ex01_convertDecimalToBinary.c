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
    while (decimalNum > 0)
    {
        r = decimalNum % 2;
        decimalNum /= 2;
        binaryNum = binaryNum + r * p;
        p *= 10;
    }

    printf("10 ������ = %d\n", inputNum);
    printf(" 2 ������ = %d\n\n", binaryNum);

    return 0;
}