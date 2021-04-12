#include <stdio.h>
int main() {
    int height;

    printf("피라미드의 높이: ");
    scanf("%d", &height);

    for (int i = 1; i <= height; i++) {

        // 공백 출력 => 피라미드 높이보다 하나 작은만큼 공백 출력
        for (int space = 1; space <= height - i; space++) {
            printf(" ");
        }

        // '*' 출력
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("*");

        printf("\n");
    }
    return 0;
}