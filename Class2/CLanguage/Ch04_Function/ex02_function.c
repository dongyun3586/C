#include <stdio.h>

void add(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);
void divide(int a, int b);

void main()
{
    int a, b;

    printf("정수 두 개 입력: ");
    scanf("%d %d", &a, &b);

    add(a, b);
    subtract(a, b);
    multiply(a, b);
    divide(a, b);
}

void add(int a, int b)
{
    printf("%d + %d = %d\n", a, b, a + b);
}

void subtract(int a, int b)
{
    printf("%d - %d = %d\n", a, b, a - b);
}

void multiply(int a, int b)
{
    printf("%d * %d = %d\n", a, b, a * b);
}

void divide(int a, int b)
{
    printf("%d / %d = %.2f\n", a, b, (float)a / b);
}