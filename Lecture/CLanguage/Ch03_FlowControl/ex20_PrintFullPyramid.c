#include <stdio.h>
int main_ex20_PrintFullPyramid() {
    int h;

    printf("�Ƕ�̵��� ����: ");
    scanf("%d", &h);

    for (int i = 1; i <= h; i++) {
        // ���� ��� => �Ƕ�̵� ���̺��� �ϳ� ������ŭ ���� ���
        for (int j = 1; j <= h - i; j++) 
            printf(" ");

        // '*' ���
        for (int k = 1; k <= 2 * i - 1; k++)
            printf("*");

        printf("\n");
    }
    return 0;
}