#include <stdio.h>

int main() {
    int h;
    printf("�Ƕ�̵��� ����: ");
    scanf("%d", &h);

    // Full Pyramid ���
    for (int i = 1; i <= h; i++) {
        // ���� ��� h-1 ~ 0
        for (int j = h - i; j > 0; j--)
            printf(" ");

        // �� ��� 1, 3, 5, 7, 9 ~ h*2-1
        for (int j = 0; j < i * 2 - 1; j++) 
            printf("*");
            
        printf("\n");
    }


    // Reverse Full Pyramid ���
    for (int i = 0; i < h; i++) {
        // ���� ���  0 ~ h-1
        for (int j = 0; j < i; j++)
            printf(" ");

        // �� ��� h*2-1 ~ 1     
        for (int j = 0; j < (h-i)*2-1; j++)
            printf("*");

        printf("\n");
    }


    return 0;
}