#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int n, count = 0, a, b;

    printf("�Է� ����: ");
    scanf("%d", &n);
    a = n;

    while (n > 0) {
        n /= 10;
        count++;
    }

    printf("��� ����: ");
    /*for (int i = 0; i < count; i++) {
        b = a % 10;
        a = a - b * 10
            printf("%d", b);
    }*/

    return 0;
}