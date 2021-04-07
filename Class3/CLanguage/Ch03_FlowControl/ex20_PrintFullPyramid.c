#include <stdio.h>

int main() {
    int h;

    printf("피라미드의 높이: ");
    scanf("%d", &h);

    for (int i = 1; i <= h; i++) {
        // 공백 반복 출력
        for (int s = 1; s <= h - i; s++)
            printf(" ");

        // 별 반복 출력
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("*");

        printf("\n");
    }

    return 0;
}