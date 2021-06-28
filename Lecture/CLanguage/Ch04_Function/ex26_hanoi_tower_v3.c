#include <stdio.h>

void hanoi(int n, char from, char other, char to);

int main()
{
    int n;
    printf("하노의 탑의 원판의 개수: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}

void hanoi(int n, char from, char other, char to)
{
    printf("호출 hanoi(%d, %c, %c, %c)\n", n, from, other, to);
    if (n == 1) {
        printf("%d번째 원반 : ", n);
        printf("%c -> %c\n", from, to);
        printf("반환\n");
        return;
    }
    hanoi(n - 1, from, to, other);
    printf("%d번째 원반 : ", n);
    printf("%c -> %c\n", from, to);
    hanoi(n - 1, other, from, to);
}