#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int a = 0, num = 0, b = 0, c = 1, d = 1;

    while (b == 0) {
        printf("�Է� ����: ");
        scanf("%ld", &a);
        for (int i = 1; i < c; i++)
            d *= 10;
        num = num + a * d;
        d = 1;
        c += 1;
    }
    

    printf("��� ����: %d ", num);

    return 0;
}