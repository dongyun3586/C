#include <stdio.h>

int main() {
    int h;
    printf("피라미드의 높이: ");
    scanf("%d", &h);

    // Half Pyramid 출력
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= i; ++j)
            printf("*");
        printf("\n");
    }

    // Reverse Half Pyramid 출력
    for (int i = 0; i < h; i++) {
        for (int j = h - i; j > 0; j--)
            printf("*");
        printf("\n");
    }

    return 0;
}