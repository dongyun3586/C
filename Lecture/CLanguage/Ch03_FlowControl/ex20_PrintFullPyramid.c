#include <stdio.h>
int main_ex20_PrintFullPyramid() {
    int height;

    printf("�Ƕ�̵��� ����: ");
    scanf("%d", &height);

    for (int i = 1; i <= height; i++) {

        // ���� ��� => �Ƕ�̵� ���̺��� �ϳ� ������ŭ ���� ���
        for (int space = 1; space <= height - i; space++) {
            printf(" ");
        }

        // '*' ���
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("*");

        printf("\n");
    }
    return 0;
}