#include <stdio.h>
#include "MyMath.h"

void main()
{
    int a, b, result;

    printf("정수 두 개 입력: ");
    scanf("%d %d", &a, &b);

    add(a, b);
    subtract(a, b);
    multiply(a, b);
    divide(a, b);
}