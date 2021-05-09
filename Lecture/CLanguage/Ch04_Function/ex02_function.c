#include <stdio.h>
//#include <myMath.h>

void main_ex02_function()
{
    int a, b;

    printf("정수 두 개 입력: ");
    scanf("%d %d", &a, &b);

    add(a, b);
    subtract(a, b);
    multiply(a, b);
    divide(a, b);
}