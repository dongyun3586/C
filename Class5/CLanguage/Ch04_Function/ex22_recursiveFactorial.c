#include <stdio.h>
int factorial(int n);

int main()
{
    int n = 5;
    printf("%2d! = %6d\n", n, factorial(n));
    return 0;
}

int factorial(int n)
{
    if (n == 1)      // n�� 1�� ��
        return 1;    // 1�� ��ȯ�ϰ� ���ȣ���� ����
    return n * factorial(n - 1);    // n�� factorial �Լ��� n - 1�� �־ ��ȯ�� ���� ����
}