#include <stdio.h>

/* �� �Ƕ�̵� ��� */
int main() {
    int i = 0, n = 0, m = 0, j = 0;

    printf("����: ");
    scanf("%d", &n);

    m=n;
    for (m; m > 0;m--) {
        for (i = n - m; i > 0; i--)
            printf(" ");
        for (j = 2 * -1; j > 0; j--)
            printf("*");
        printf("\n");
    }

    return 0;
}