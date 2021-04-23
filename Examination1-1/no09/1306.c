#include <stdio.h>

/* 정수 뒤집어서 출력하기 */
int main() {
    int a, b = 0;

    printf("입력 정수: ");
    scanf("%d", &a);

    while (a > 10) {
        b *= 10;
        b = a % 10;
        a /= 10;
    }
    b *= 10;
    b += a;
    printf("출력정수: %d", b);

    return 0;
}