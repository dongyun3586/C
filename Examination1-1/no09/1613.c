#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int a, b, c, t, d, e = 1;

    printf("�Է� ����: ");
    scanf("%d", &a);

    while (1) {
        c = a / 10;
        if (c == 0) break;
        else t++;
    }

    for (int k = 1; k <= t; k++) {
        for (int j = 1; j <= k; j++)
            e *= 10;
    }

    printf("��� ����: %d", b);

    return 0;
}