#include <stdio.h>

// calculator( )�Լ� ����

int main()
{
    int a, b;
    int sum, subtract, multiply;
    float divide;

    printf("���� ���� �� �� �Է�: ");
    scanf("%d%d", &a, &b);

    // calculator( ) �Լ� ȣ��
    printf("%d + %d = %d\n", a, b, sum);
    printf("%d - %d = %d\n", a, b, subtract);
    printf("%d * %d = %d\n", a, b, multiply);
    printf("%d / %d = %f\n", a, b, divide);

    return 0;
}

// calculator( ) �Լ� ����