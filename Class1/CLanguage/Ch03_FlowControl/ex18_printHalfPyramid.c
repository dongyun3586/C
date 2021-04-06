#include <stdio.h>

int main_ex18_printHalfPyramid() {
    int i, j, height;
    printf("피라미드의 높이: ");
    scanf("%d", &height);

    for (i = 1; i <= height; i=i-3) {
        for (j = 1; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}