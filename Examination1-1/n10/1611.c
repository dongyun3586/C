#include <stdio.h>

/* 역 피라미드 출력 */
int main() {
    int i, j, n;

    printf("높이: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++)
            printf(" ");
        for (int j = n; j >= 2*n - 1; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}