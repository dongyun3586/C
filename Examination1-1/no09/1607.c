#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int n;

    printf("�Է� ����: ");
    scanf("%d", &n);

    printf("��� ����: ");
    while (n >= 0) {
        printf("%d", n%10);
        int m = n / 10;
        n = m;
    }

    return 0;
}