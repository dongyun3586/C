#include <stdio.h>

int main_ex18_PrintHalfPyramid() {
    int i, j, height;
    printf("피라미드의 높이: ");
    scanf("%d", &height);
    for (i = 1; i <= height; ++i) {
        for (j = 1; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}