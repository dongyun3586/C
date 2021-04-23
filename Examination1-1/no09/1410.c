#include <stdio.h>

/* 정수 뒤집어서 출력하기 */
int main() {
    int a,b,c;

    printf("입력 정수: ");
    scanf("%d", &a);

    printf("출력 정수: ");
    while (a/10 != 0) {
        b = a % 10;
        c = a / 10;
        a = c;
        printf("%d", b);
    }

    return 0;
}