#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int n, r;

    printf("�Է� ����: ");
    scanf("%d", &n);

    printf("��� ����: ");
    while (n != 0) {
        r = n % 10;
        n = n / 10;
        printf("%d", r);
    }

    return 0;
}