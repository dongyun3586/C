#include <stdio.h>

void hanoi(int n, int from, int other, int to);

int main()
{
    int n;
    printf("하노의 탑의 원판의 개수: ");
    scanf("%d", &n);
    hanoi(n, 1, 2, 3);
    return 0;
}

void hanoi(int n, int from, int other, int to)
{
    printf("호출 hanoi(%d, %d, %d, %d)\n", n, from, other, to);
    if (n == 1) {
        printf("%d번째 원반 : ", n);
        printf("%d -> %d\n", from, to);
        printf("반환\n");
        return;
    }
    hanoi(n - 1, from, to, other);
    printf("%d번째 원반 : ", n);
    printf("%d -> %d\n", from, to);
    hanoi(n - 1, other, from, to);
}