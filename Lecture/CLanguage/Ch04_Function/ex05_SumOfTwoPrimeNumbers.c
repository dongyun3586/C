#include <stdio.h>

int main() {
    int n, flag = 0;
    printf("���� ����: ");
    scanf("%d", &n);

    // n�� �Ҽ��� ������ ǥ���Ǵ� ��� ���
    for(int i = 2; i <= n / 2; ++i) {
        // condition for i to be a prime number
        if (checkPrimeNumber(i) == 1) {
            // condition for n-i to be a prime number
            if (checkPrimeNumber(n - i) == 1) {
                printf("%d = %d + %d\n", n, i, n - i);
                flag = 1;
            }
        }
    }

    if(flag == 0)
        printf("%d �� �Ҽ��� ������ ǥ���� �� �����ϴ�.\n", n);

    return 0;
}