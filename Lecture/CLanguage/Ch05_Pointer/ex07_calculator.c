#include <stdio.h>

// calculator( )�Լ� ����
void calculator(int a, int b, int* sum, int* sub, int* mul, float* div);

int main()
{
    int a, b;
    int sum, subtract, multiply;
    float divide;

    printf("���� ���� �� �� �Է�: ");
    scanf("%d%d", &a, &b);

    // calculator( ) �Լ� ȣ��
    calculator(a, b, &sum, &subtract, &multiply, &divide);

    printf("%d + %d = %d\n", a, b, sum);
    printf("%d - %d = %d\n", a, b, subtract);
    printf("%d * %d = %d\n", a, b, multiply);
    printf("%d / %d = %f\n", a, b, divide);

    return 0;
}

// calculator( ) �Լ� ����
void calculator(int a, int b, int* sum, int* sub, int* mul, float* div) {
    *sum = a + b;
    *sub = a - b;
    *mul = a * b;
    *div = (float)a / b;
}