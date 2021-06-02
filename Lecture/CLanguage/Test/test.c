#include <stdio.h>
#include <math.h>

int reverse(int num);

int main()
{
    int num, rev;

    printf("양의 정수 입력: ");
    scanf("%d", &num);

    rev = reverse(num);
    printf("Reverse of %d = %d", num, reverse(num));

    return 0;
}


int reverse(int num)
{
    int n = (int)log10(num);

    if (num == 0)
        return 0;

    return ((num % 10 * pow(10, n)) + reverse(num / 10));
}