#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int n;

    printf("�Է� ����: ");
    scanf("%d", &n);

    printf("��� ����: ");
    while (n >= 1) {
        printf("%d", n % 10);
        n = / 10;
    }

    return 0;
}