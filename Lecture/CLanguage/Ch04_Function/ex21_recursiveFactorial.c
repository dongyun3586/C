#include <stdio.h>

int factorial(int n);

int main()
{
    for (int i = 1; i <= 10; i++)
        printf("%2d! = %7d\n", i, factorial(i));

    return 0;
}

int factorial(int n)
{
    if (n == 1)      // n�� 1�� ��
        return 1;    // 1�� ��ȯ�ϰ� ���ȣ���� ����

    return n * factorial(n - 1);    // n�� factorial �Լ��� n - 1�� �־ ��ȯ�� ���� ����
}