#include <stdio.h>

/* 정수 뒤집어서 출력하기 */
int main() {
    int n;

    printf("입력 정수: ");
    scanf("%d", &n);

    while (1) {
        printf("%d", n%10);
        n /= 10;
        if (n < 10)break;
    }
    printf("%d", n);

    return 0;
}