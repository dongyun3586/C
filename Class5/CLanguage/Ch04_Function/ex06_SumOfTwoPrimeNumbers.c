#include <stdio.h>

int checkPrimeNumber(int n);

int main() {
    int n, flag = 0;     // flag ���� �̿��Ͽ� �Ҽ��� ������ ǥ���� �� ���� ��� ó��
    printf("���� ����: ");
    scanf("%d", &n);

    // n�� �Ҽ��� ������ ǥ���Ǵ� ��츦 ��� ���

    return 0;
}

int checkPrimeNumber(int n) {
    if (n < 2) return 0;
    for (int i = 2; i < n; i++)
        if (n % i == 0) return 0;
    return 1;
}