#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int n, a = 1, count = 1;

    printf("�Է� ����: ");
    scanf("%d", &n);

    while (a != 0) {
        a = n;
        if ((a / 10) != 0) {
            count += 1;

        }
    }

    return 0;
}