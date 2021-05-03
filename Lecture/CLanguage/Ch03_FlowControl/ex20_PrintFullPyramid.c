#include <stdio.h>
int main_ex20_PrintFullPyramid() {
    int h;

    printf("피라미드의 높이: ");
    scanf("%d", &h);

    for (int i = 1; i <= h; i++) {
        // 공백 출력 => 피라미드 높이보다 하나 작은만큼 공백 출력
        for (int j = 1; j <= h - i; j++) 
            printf(" ");

        // '*' 출력
        for (int k = 1; k <= 2 * i - 1; k++)
            printf("*");

        printf("\n");
    }
    return 0;
}