#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int a, b;

    printf("�Է� ����: ");
    scanf("%d", &a);

    printf("��� ����: ");
    while (a > 0) {
        b = a % 10;
        a = a / 10;
        printf("%d", b);
    }

    return 0;
}