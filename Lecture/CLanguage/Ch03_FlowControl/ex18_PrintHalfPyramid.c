#include <stdio.h>

int main_ex18_PrintHalfPyramid() {
    int i, j, height;
    printf("�Ƕ�̵��� ����: ");
    scanf("%d", &height);
    for (i = 1; i <= height; ++i) {
        for (j = 1; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}