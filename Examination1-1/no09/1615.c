#include <stdio.h>

/* 정수 뒤집어서 출력하기 */
int main() {
    int n, x;

    printf("입력 정수: ");
    scanf("%d", &n);

    printf("\n출력 정수: ");
    while (n > 0) {
        x = n % 10;
        n = n / 10;
        printf("%d", x);
    }

    return 0;
}