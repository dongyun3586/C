#include <stdio.h>

void printLine(int n);

void main()
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

void printLine(int n) 
{
    for (int i = 0; i < n; i++)
        printf("-");
    printf("\n");
}

