#include <stdio.h>

/* ���� ����� ����ϱ� */
int main() {
    int num, sum, temp;

    printf("�Է� ����: ");
    scanf("%d", &num);

    temp = num;
    while (temp > 0) {
        sum = sum + temp % 10;
        sum *= 10;
        temp /= 10;
    }
    sum /= 10;

    printf("��� ����: %d", sum);
    return 0;
}