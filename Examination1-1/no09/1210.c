#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int a, n;

    printf("�Է� ����: ");
    scanf("%d", &n);

    printf("��� ����: ");
    while (n > 0) {
        a = n % 10;
        n = (n - n % 10 * 10) / 10;
        printf("%d", a);
    }

    return 0;
}