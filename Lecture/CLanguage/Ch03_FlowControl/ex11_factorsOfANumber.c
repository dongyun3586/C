#include <stdio.h>

int main_ex11_factorsOfANumber() {
    int num, i;
    printf("���� ������ �Է��Ͻÿ�: ");
    scanf("%d", &num);
    printf("%d�� ����� : ", num);
    for (i = 1; i <= num; ++i) {
        if (num % i == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}