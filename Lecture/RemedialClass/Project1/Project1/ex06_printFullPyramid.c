#include <stdio.h>

int main() {
    int h;
    printf("�Ƕ�̵��� ����: ");
    scanf("%d", &h);

    // Full Pyramid ���
    for (int i = 1; i <= h; i++) {
        // ���� ���
        for (int j = h - i; j > 0; j--)
            printf(" ");
        // �� ���
        for (int j = 0; j < i * 2 - 1; j++)
            printf("*");
        printf("\n");
    }

    // Reverse Half Pyramid ���
    for (int i = 0; i < h; i++) {
        // ���� ���
        for (int j = 0; j < i; j++)
            printf(" ");
        // �� ���
        for (int j = 0; j < (h - i) * 2 - 1; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}