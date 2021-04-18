#include <stdio.h>

int main() {
    int n, flag = 0;
    printf("양의 정수: ");
    scanf("%d", &n);

    // n을 소수의 합으로 표현되는 경우 출력
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
        printf("%d 는 소수의 합으로 표현할 수 없습니다.\n", n);

    return 0;
}