#include <stdio.h>

void hanoi(int n, int to, int from, int other);

int main()
{
    int n;
    printf("�ϳ��� ž�� ������ ����: ");
    scanf("%d", &n);
    hanoi(n, 1, 3, 2);
    return 0;
}

void hanoi(int n, int from, int to, int other)
{
    //printf("ȣ�� hanoi(%d, %d, %d, %d)\n", n, from, to, other);
    if (n == 1) {
        //printf("%d��° ���� : ", n);
        printf("%d -> %d\n", from, to);
        //printf("��ȯ\n");
        return;
    }
    hanoi(n - 1, from, other, to);
    //printf("%d��° ���� : ", n);
    printf("%d -> %d\n", from, to);
    hanoi(n - 1, other, to, from);
}