#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int n;

    printf("�Է� ����: ");
    scanf("%d", &n);

    while (1) {
        printf("%d", n%10);
        n /= 10;
        if (n < 10)break;
    }
    printf("%d", n);

    return 0;
}