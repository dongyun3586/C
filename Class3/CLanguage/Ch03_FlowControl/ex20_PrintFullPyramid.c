#include <stdio.h>

int main() {
    int h;

    printf("�Ƕ�̵��� ����: ");
    scanf("%d", &h);

    for (int i = 1; i <= h; i++) {
        // ���� �ݺ� ���
        for (int s = 1; s <= h - i; s++)
            printf(" ");

        // �� �ݺ� ���
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("*");

        printf("\n");
    }

    return 0;
}