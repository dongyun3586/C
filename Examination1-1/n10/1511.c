#include <stdio.h>

/* 역 피라미드 출력 */
int main() {
    int a, i, j, k, t;

    printf("높이: ");
    scanf("%d", &a);

    t = a;
    for (int i = 0; i < a; i++) {
        for (int j = 1; j < i; j++)
            printf(" ");
        for (int j = t*2-1; j >= i; j--)
            printf("*");
        t--;
        printf("\n");
    }

    return 0;
}