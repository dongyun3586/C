#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int num, i, a, k, cnt = 0;

    printf("�Է� ����: ");
    scanf("%d", &num);

    k = num;
    while (k > 0) {
        k /= 10;
        cnt++;
    }

    for (i = 1; i <= cnt; i++) {
        a = num % 10;
        for (int j = 1; j <= cnt - i + 1; j++) {
            a *= 10;
            num / 10;
        }
    }

    printf("%d",a);

    return 0;
}