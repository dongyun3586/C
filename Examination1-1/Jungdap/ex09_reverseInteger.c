#include <stdio.h>

/* 정수 뒤집어서 출력하기 */
int main() {
    int n, r;

    printf("입력 정수: ");
    scanf("%d", &n);

    printf("출력 정수: ");
    while (n != 0) {
        r = n % 10;
        n = n / 10;
        printf("%d", r);
    }

    return 0;
}