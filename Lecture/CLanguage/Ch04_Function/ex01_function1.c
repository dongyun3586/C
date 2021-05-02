#include <stdio.h>

void main_ex01_function1()
{
    int a, b;

    printf("두 정수의 사칙연산 프로그램\n\n");

    printf("정수 두 개 입력: ");
    scanf("%d %d", &a, &b);
    printf("\n");

    // add
    printf("%d + %d = %d\n", a, b, a + b);

    // subtract
    printf("%d - %d = %d\n", a, b, a - b);

    // multiply
    printf("%d * %d = %d\n", a, b, a * b);

    // divide
    printf("%d / %d = %.2f\n", a, b, (float)a / b);
}