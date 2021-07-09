#include <stdio.h>
#include <math.h>
int reverse(int num);

int main() {
    // �� ���� ���� [2��]
    int n, n2;

    // �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
    printf("���� ���� �Է�: ");
    scanf("%d", &n);

    // �� ó�� �� ��� [2��]
    printf("Reverse of %d = %d", n, reverse(n));

    return 0;
}

// �� reverse �Լ� [4��]
int reverse(int num) {
    if (num == 0)return 0;
    int tmp = log10(num);
    int now = num / pow(10, tmp);
    return now + 10 * reverse(num % (int)pow(10, tmp));
}