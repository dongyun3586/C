#include <stdio.h>
int main_ex11_factorsOfANumber() {
    int num;
    printf("���� ������ �Է��Ͻÿ�: ");
    scanf("%d", &num);
    printf("%d�� ����� : ", num);

    // �ݺ����� ����Ͽ� ��� ��� ����ϱ�
    for (int i = 1; i <= num; i++) {
        if (num % i == 0)
            printf("%d ", i);
    }

    printf("\n");
    return 0;
}