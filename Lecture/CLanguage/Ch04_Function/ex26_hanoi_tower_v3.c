#include <stdio.h>

void hanoi(int n, char from, char other, char to);

int main()
{
    int n;
    printf("�ϳ��� ž�� ������ ����: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}

void hanoi(int n, char from, char other, char to)
{
    printf("ȣ�� hanoi(%d, %c, %c, %c)\n", n, from, other, to);
    if (n == 1) {
        printf("%d��° ���� : ", n);
        printf("%c -> %c\n", from, to);
        printf("��ȯ\n");
        return;
    }
    hanoi(n - 1, from, to, other);
    printf("%d��° ���� : ", n);
    printf("%c -> %c\n", from, to);
    hanoi(n - 1, other, from, to);
}