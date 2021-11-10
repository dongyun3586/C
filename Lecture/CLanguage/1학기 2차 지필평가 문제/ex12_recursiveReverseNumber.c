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
    int n = log10(num);
    if (num == 0)
        return 0;
    return ((num % 10 * pow(10, n)) + reverse(num / 10));
}