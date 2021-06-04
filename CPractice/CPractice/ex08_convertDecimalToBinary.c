#include <stdio.h>

int main()
{
    int inputNum, decimalNum, binaryNum = 0;
    int r, n = 1;

    // 십진수값 입력받기
    printf("십진수 입력: ");
    scanf("%d", &inputNum);
    decimalNum = inputNum;

    // 10진수 -> 2진수 변환
    // 1. while문 사용
    while (decimalNum > 0) {
        r = decimalNum % 2;
        binaryNum += (r * n);
        decimalNum /= 2;
        n *= 10;
    }

    printf("\nwhile문 사용\n");
    printf("10 진수값 = %d\n", inputNum);
    printf(" 2 진수값 = %d\n\n", binaryNum);

    binaryNum = 0;
    n = 1;
    // 2. for문 사용
    for (decimalNum = inputNum; decimalNum > 0; decimalNum /= 2) {
        r = decimalNum % 2;
        binaryNum += (r * n);
        n *= 10;
    }

    printf("for문 사용\n");
    printf("10 진수값 = %d\n", inputNum);
    printf(" 2 진수값 = %d\n\n", binaryNum);

    return 0;
}