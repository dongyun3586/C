#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int a, b;

    printf("�Է� ����: ");
    scanf("%d", &a);

    while (a != 0) {
        if (a % 10 != 0) {
            b = a % 10;
            printf("%d", b);
        }
        a /= 10;
    }

    return 0;
}