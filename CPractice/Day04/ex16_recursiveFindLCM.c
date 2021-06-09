#include <stdio.h>
#include <limits.h>

long long lcm(long long a, long long b);
long long multiple = 0;

int main()
{
    long long num1, num2, LCM;

    printf("INT_MAX = %d\n", INT_MAX);
    printf("LLONG_MAX = %lld\n", LLONG_MAX);

    printf("�ּ� ������� ã�� �� �� �Է�: ");
    scanf("%lld %lld", &num1, &num2);

    // �� ��ȯ �۾��� ���ص� �ּҰ������ ��������. ������ �ݺ� Ƚ���� �پ���.
    int temp;
    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    printf("LCM(%lld, %lld) = %lld\n", num1, num2, lcm(num1, num2));

    return 0;
}

long long lcm(long long a, long long b) {
    multiple += b;

    if (multiple % a == 0 && multiple % b == 0)
        return multiple;
    return lcm(a, b);
}