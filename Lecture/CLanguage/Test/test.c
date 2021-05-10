#include <stdio.h>

int checkPrimeNumber(int n);

int main() {
    int n, flag = 1;
    printf("���� ����: ");
    scanf("%d", &n);

    // n�� �Ҽ��� ������ ǥ���Ǵ� ��� ���
    for (int i = 2; i <= n / 2; ++i) {
        // condition for i to be a prime number
        if (checkPrimeNumber(i) && checkPrimeNumber(n - i)) {
            printf("%d = %d + %d\n", n, i, n - i);
            flag = 0;
        }
    }

    if (flag)
        printf("%d �� �Ҽ��� ������ ǥ���� �� �����ϴ�.\n", n);

    return 0;
}

int checkPrimeNumber(int n) {
    if (n < 2) return 0;
    for (int i = 2; i < n; i++)
        if (n % i == 0) return 0;
    return 1;
}