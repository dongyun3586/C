#include <stdio.h>

int main_ex19_PrintInvertedHalfPyramid() {
    int i, j, height;
    printf("�Ƕ�̵��� ����: ");
    scanf("%d", &height);
    for (i = height; i >= 1; --i) {
        for (j = 1; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}