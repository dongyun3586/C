#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int a, b = 0;

    printf("�Է� ����: ");
    scanf("%d", &a);

    while (a > 10) {
        b *= 10;
        b = a % 10;
        a /= 10;
    }
    b *= 10;
    b += a;
    printf("�������: %d", b);

    return 0;
}