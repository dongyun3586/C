#include <stdio.h>

void calculator(int a, int b, int* sum, int* subtract, int* multiply, int* divide);

int main()
{
    int a, b;
    int sum, subtract, multiply;
    float divide;

    printf("양의 정수 두 개 입력: ");
    scanf("%d%d", &a, &b);

    calculator(a, b, &sum, &subtract, &multiply, &divide);
    printf("%d + %d = %d\n", a, b, sum);
    printf("%d - %d = %d\n", a, b, subtract);
    printf("%d * %d = %d\n", a, b, multiply);
    printf("%d / %d = %f\n", a, b, divide);

    return 0;
}

void calculator(int a, int b, int* sum, int* subtract, int* multiply, float* divide) {
    *sum = a + b;
    *subtract = a - b;
    *multiply = a * b;
    *divide = (float)a / b;
}