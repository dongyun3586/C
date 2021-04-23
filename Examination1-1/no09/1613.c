#include <stdio.h>

/* 정수 뒤집어서 출력하기 */
int main() {
    int a, b, c, t, d, e = 1;

    printf("입력 정수: ");
    scanf("%d", &a);

    while (1) {
        c = a / 10;
        if (c == 0) break;
        else t++;
    }

    for (int k = 1; k <= t; k++) {
        for (int j = 1; j <= k; j++)
            e *= 10;
    }

    printf("출력 정수: %d", b);

    return 0;
}