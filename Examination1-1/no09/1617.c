#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int n, i=1;

    printf("�Է� ����: ");
    scanf("%d", &n);

    while (1) {
        if (n / > 0) {
            i *= 10;
            printf("%d", n % i);
        }
        else
            break;
    }

    return 0;
}