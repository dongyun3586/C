#include <stdio.h>

/* �� �Ƕ�̵� ��� */
int main() {
    int n;

    printf("����: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++)
            printf(" ");
        for (int j = 1; j < 2 * (n - i+1) -1; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}