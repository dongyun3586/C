#include <stdio.h>

void printLine(int n);  // �Լ� ���� ����

void main_ex01_function3()
{
    int a, b;

    printf("�� ������ ��Ģ���� ���α׷�\n");
    printLine(30);

    printf("\n���� �� �� �Է�: ");
    scanf("%d %d", &a, &b);
    printf("\n");

    // add
    printf("%d + %d = %d\n", a, b, a + b);
    printLine(15);

    // subtract
    printf("%d - %d = %d\n", a, b, a - b);
    printLine(15);

    // multiply
    printf("%d * %d = %d\n", a, b, a * b);
    printLine(15);

    // divide
    printf("%d / %d = %.2f\n", a, b, (float)a / b);
    printLine(15);
}

