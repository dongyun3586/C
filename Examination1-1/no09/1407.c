#include <stdio.h>

/* 정수 뒤집어서 출력하기 */
int main() {
    int a, b;

    printf("입력 정수: ");
    scanf("%d", &a);

    while (a != 0) {
        if (a % 10 != 0) {
            b = a % 10;
            printf("%d", b);
        }
        a /= 10;
    }

    return 0;
}