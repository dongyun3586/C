#include <stdio.h>

int main_ex18_printHalfPyramid() {
    int i, j, height;
    printf("�Ƕ�̵��� ����: ");
    scanf("%d", &height);
    for (i = 1; i <= height; i=i+5) {
        for (j = 1; j <= i; ++j) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}