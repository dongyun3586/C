#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int a = 0, b = 0, c = 0;

    printf("�Է� ����: ");
    scanf("%d", &a);

    printf("��� ����: ");
    while (1) {
        b = a % 10;
        c = (a - b) / 10;
        printf("%d", &b);
        
        if (b == 0)
            break;
    }

    return 0;
}