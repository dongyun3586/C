#include <stdio.h>

/* �� �Ƕ�̵� ��� */
int main() {
    int h, k;

    printf("����: ");
    scanf("%d", &h);

    for (int i = 1; i <= h; i++) {
        for (int j = 0; j > i - 1; j++)
            printf(" ");
        k = i - 1, k = k * 2;
        for (int j = 0; j < h * 2 - 1 - k; j++)
            printf("*");
    }

    return 0;
}