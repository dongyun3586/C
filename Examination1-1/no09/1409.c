#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int n, m, c = 0, i;

    printf("�Է� ����: ");
    scanf("%d", &n);

    m = n;
    while (m > 0) {
        m /= 10;
        c++;
    }

    printf("��� ����: ");
    for(i=0;i<c;i++)
        printf("%d", n / (10 ^ i) - (n / (10 ^ (i + 1))) * 10);

    return 0;
}