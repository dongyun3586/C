#include <stdio.h>

int main_ex15_countNumberOfDigitsInAnInteger() {
    int number, count = 0;  // INT_MAX = 2,147,483,647

    printf("���� ������ �Է��Ͻÿ�: ");
    scanf("%d", &number);

    // while���� ����Ͽ� ������ �ڸ��� ���ϱ�
    while (number != 0) {
        number /= 10;
        count++;
    }

    printf("�ڸ���: %d \n", count);
}