#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int a,b,c;

    printf("�Է� ����: ");
    scanf("%d", &a);

    printf("��� ����: ");
    while (a/10 != 0) {
        b = a % 10;
        c = a / 10;
        a = c;
        printf("%d", b);
    }

    return 0;
}