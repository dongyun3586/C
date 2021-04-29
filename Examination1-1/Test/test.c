#include <stdio.h>

/* 정수 뒤집어서 출력하기 */
int main() {
    int n, count = 0, a, b;

    printf("입력 정수: ");
    scanf("%d", &n);
    a = n;

    while (n > 0) {
        n /= 10;
        count++;
    }

    printf("출력 정수: ");
    /*for (int i = 0; i < count; i++) {
        b = a % 10;
        a = a - b * 10
            printf("%d", b);
    }*/

    return 0;
}