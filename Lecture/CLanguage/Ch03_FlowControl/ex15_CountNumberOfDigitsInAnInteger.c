#include <stdio.h>

int main_ex14_CountNumberOfDigitsInAnInteger() {
    int number, count = 0;  // INT_MAX = 2,147,483,647

    printf("���� ������ �Է��Ͻÿ�: ");
    scanf("%d", &number);

    while (number != 0) {
        number /= 10;     
        count++;
    }

    printf("�ڸ���: %d \n", count);
}