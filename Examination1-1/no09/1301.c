#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int n, k;

    printf("�Է� ����: ");
    scanf("%d", &n);

    printf("��� ����: ");
    while (n > 0) {
        k = n;
        while (1) {
            if (k < 10) {
                printf("%d", k);
                break;
            }
            k %= 10;
        }
        n %= 10;
    }

    return 0;
}