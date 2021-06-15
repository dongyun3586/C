#include <stdio.h>

int main()
{
    int inputNum, decimalNum, binaryNum = 0;
    int r, p = 1;

    // 십진수값 입력받기
    printf("십진수 입력: ");
    scanf("%d", &inputNum);
    decimalNum = inputNum;

    // 10진수 -> 2진수 변환
    while (decimalNum > 0)
    {
        r = decimalNum % 2;
        decimalNum /= 2;
        binaryNum = binaryNum + r * p;
        p *= 10;
    }

    printf("10 진수값 = %d\n", inputNum);
    printf(" 2 진수값 = %d\n\n", binaryNum);

    return 0;
}