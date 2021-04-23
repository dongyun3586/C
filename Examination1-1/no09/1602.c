#include <stdio.h>

/* 정수 뒤집어서 출력하기 */
int main() {
    int a, b;

    printf("입력 정수: ");
    scanf("%d", &a);

    printf("출력 정수: ");
    while (a > 0) {
        b = a % 10;
        a = a / 10;
        printf("%d", b);
    }

    return 0;
}