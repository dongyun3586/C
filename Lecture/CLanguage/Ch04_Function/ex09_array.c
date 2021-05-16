#include <stdio.h>

int main()
{
    int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };

    printf("%d\n", sizeof(numArr[0]));              // 배열 요소 하나의 크기(byte)
    printf("%d\n", sizeof(numArr));                 // 배열의 크기(byte)
    printf("%d\n", sizeof(numArr) / sizeof(int));   // 배열의 요수 개수

    // 배열의 요소를 모두 출력
    for (int i = 0; i < 10; i++)
        printf("numArr[%d] = %d\n", i, numArr[i]);

    return 0;
}