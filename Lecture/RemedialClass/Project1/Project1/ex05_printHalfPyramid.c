#include <stdio.h>

int main() {
    int h;
    printf("�Ƕ�̵��� ����: ");
    scanf("%d", &h);

    // Half Pyramid ���
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= i; ++j)
            printf("*");
        printf("\n");
    }

    // Reverse Half Pyramid ���
    for (int i = 0; i < h; i++) {
        for (int j = h - i; j > 0; j--)
            printf("*");
        printf("\n");
    }

    return 0;
}