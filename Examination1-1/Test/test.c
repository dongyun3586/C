#include <stdio.h>

/* �� �Ƕ�̵� ��� */
int main() {
    int h, k;

    printf("����: ");
    scanf("%d", &h);

    for (int i=0; i > 0; i--) {
        for (int j = h-i; j > 0; j --)  // 2 * h - 1 - 2 * i
            printf("\n");
        for (int j = 2*h-1; j > 0; j--)  printf(" ");   // j <= i-1
            printf("*");
        
    }

    return 0;
}