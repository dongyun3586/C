#include <stdio.h>

void hanoi(int n, int from, int other, int to);

int main()
{
    int n;
    printf("�ϳ��� ž�� ������ ����: ");
    scanf("%d", &n);
    hanoi(n, 1, 2, 3);
    return 0;
}

void hanoi(int n, int from, int other, int to)
{
    printf("ȣ�� hanoi(%d, %d, %d, %d)\n", n, from, other, to);
    if (n == 1) {
        printf("%d��° ���� : ", n);
        printf("%d -> %d\n", from, to);
        printf("��ȯ\n");
        return;
    }
    hanoi(n - 1, from, to, other);
    printf("%d��° ���� : ", n);
    printf("%d -> %d\n", from, to);
    hanoi(n - 1, other, from, to);
}