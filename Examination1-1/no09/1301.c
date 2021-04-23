#include <stdio.h>

/* 정수 뒤집어서 출력하기 */
int main() {
    int n, k;

    printf("입력 정수: ");
    scanf("%d", &n);

    printf("출력 정수: ");
    while (n > 0) {
        k = n;
        while (1) {
            if (k < 10) {
                printf("%d", k);
                break;
            }
            k %= 10;
        }
        n %= 10;
    }

    return 0;
}