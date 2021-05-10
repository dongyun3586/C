#include <stdio.h>

int checkPrimeNumber(int n);

int main() {
    int n, flag = 0;     // flag 값을 이용하여 소수의 합으로 표현할 수 없는 경우 처리
    printf("양의 정수: ");
    scanf("%d", &n);

    // n을 소수의 합으로 표현되는 경우를 모두 출력

    return 0;
}

int checkPrimeNumber(int n) {
    if (n < 2) return 0;
    for (int i = 2; i < n; i++)
        if (n % i == 0) return 0;
    return 1;
}