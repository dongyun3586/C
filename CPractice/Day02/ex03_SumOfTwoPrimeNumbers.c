#include <stdio.h>

int checkPrimeNumber(int n);

int main() {
    int n, flag = 1;     // flag 값을 이용하여 소수의 합으로 표현할 수 없는 경우 처리
    printf("양의 정수: ");
    scanf("%d", &n);

    // n을 소수의 합으로 표현되는 경우를 모두 출력
    for (int i = 2; i <= n / 2; i++) {
        if (checkPrimeNumber(i) && checkPrimeNumber(n - i)) {
            printf("%d = %d + %d\n", n, i, n - i);
            flag = 0;
        }
    }

    if (flag) printf("%d는 소수의 합으로 표현할 수 없습니다.\n", n);

    return 0;
}

int checkPrimeNumber(int n) {
    if (n < 2) return 0;
    for (int i = 2; i < n; i++)
        if (n % i == 0) return 0;
    return 1;
}