#include <stdio.h>

int main() {
    int h;
    printf("피라미드의 높이: ");
    scanf("%d", &h);

    // Full Pyramid 출력
    for (int i = 1; i <= h; i++) {
        // 공백 출력
        for (int j = h - i; j > 0; j--)
            printf(" ");
        // 별 출력
        for (int j = 0; j < i * 2 - 1; j++)
            printf("*");
        printf("\n");
    }

    // Reverse Half Pyramid 출력
    for (int i = 0; i < h; i++) {
        // 공백 출력
        for (int j = 0; j < i; j++)
            printf(" ");
        // 별 출력
        for (int j = 0; j < (h - i) * 2 - 1; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}