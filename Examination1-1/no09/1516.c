#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int a, b, c, d, e, f = 0;

    printf("�Է� ����: ");
    scanf("%d", &a);
    b = a; d = a;
    do {
        d /= 10;
        e++;
    } while (d > 0)

    for (int i = e; i > 0; i--) {
        c = b % 10;
        b /= 10;
        f = f + 10 * c;
    }

    printf("��� ����: %d", f);

    return 0;
}