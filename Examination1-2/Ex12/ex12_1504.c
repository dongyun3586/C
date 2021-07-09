#include <stdio.h>
#include <math.h>
int reverse(int num);

int main() {
    // �� ���� ���� [2��]
    int num;

    // �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
    printf("���� ���� �Է�: ");
    scanf("%d", &num);

    // �� ó�� �� ��� [2��]
    printf("Reverse of %d = %d", num, reverse(num));

    return 0;
}

// �� reverse �Լ� [4��]
int reverse(int num) {
    if (num / 10 == 0)return num;
    return (int)pow(10, log10(num)) * (num % 10) + reverse(num / 10);
}