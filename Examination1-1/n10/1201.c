#include <stdio.h>

/* 역 피라미드 출력 */
int main() {
    int h, k;

    printf("높이: ");
    scanf("%d", &h);

    for (int i = 1; i <= h; i++) {
        for (int j = 0; j > i - 1; j++)
            printf(" ");
        k = i - 1, k = k * 2;
        for (int j = 0; j < h * 2 - 1 - k; j++)
            printf("*");
    }

    return 0;
}