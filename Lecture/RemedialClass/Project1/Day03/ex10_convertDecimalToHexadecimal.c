#include <stdio.h>

int main()
{
    char hexValues[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

    int inputNum, decimalNum;
    char hexNum[100];
    int index, rem;

    printf("10������ �Է�: ");
    scanf("%d", &inputNum);
    decimalNum = inputNum;

    index = 0;

    // 10���� �� 16���� ��ȯ
    while (decimalNum != 0)
    {
        rem = decimalNum % 16;
        decimalNum /= 16;
        hexNum[index] = hexValues[rem];
        index++;
    }

    hexNum[index] = '\0';
    strrev(hexNum);        // ���ڿ� ������

    printf("\n10 ������ = %d\n", inputNum);
    printf("16 ������ = %s", hexNum);

    return 0;
}