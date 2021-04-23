#include <stdio.h>

/* 정수 뒤집어서 출력하기 */
int main() {
    int a, n;

    printf("입력 정수: ");
    scanf("%d", &n);

    printf("출력 정수: ");
    while (n > 0) {
        a = n % 10;
        n = (n - n % 10 * 10) / 10;
        printf("%d", a);
    }

    return 0;
}