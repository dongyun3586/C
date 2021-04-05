#include <stdio.h>

int main() {
    int i, j, height;
    printf("피라미드의 높이: ");
    scanf("%d", &height);
    for (i = height; i > 0; i--) {
        for (j = 1; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}