#include <stdio.h>

void main_ex01_function1()
{
    int a, b;

    printf("�� ������ ��Ģ���� ���α׷�\n\n");

    printf("���� �� �� �Է�: ");
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