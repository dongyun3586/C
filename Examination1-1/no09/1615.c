#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int n, x;

    printf("�Է� ����: ");
    scanf("%d", &n);

    printf("\n��� ����: ");
    while (n > 0) {
        x = n % 10;
        n = n / 10;
        printf("%d", x);
    }

    return 0;
}