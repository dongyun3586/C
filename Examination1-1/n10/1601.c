#include <stdio.h>

/* 역 피라미드 출력 */
int main() {
    int n;

    printf("높이: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            printf(" ");
        for (int j = 0; j < 2 * n - 1 - 2 * i; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}