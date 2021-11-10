#include <stdio.h>

int gcd_while(int a, int b);
int gcd(int a, int b);

int main()
{
    int num1, num2;

    printf("양의 정수 두 개 입력: ");
    scanf("%d %d", &num1, &num2);

    printf("GCD of %d and %d = %d\n", num1, num2, gcd_while(num1, num2));
    printf("GCD of %d and %d = %d\n", num1, num2, gcd(num1, num2));

    return 0;
}

int gcd_while(int a, int b)
{
    int t;
    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int gcd(int a, int b)
{
    if (b == 0) return a;
    //if (a % b == 0) return b;
    else
        return gcd(b, a % b);
}