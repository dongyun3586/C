#include <stdio.h>
#include <math.h>
#define BASE 2
int main()
{
    long long binary, decimal = 0;
    int n = 0;

    printf("�Է�: ");
    scanf("%lld", &binary);

    while (binary != 0)
    {
        if (binary % 10 == 1)
            decimal += pow(BASE, n);
        n++;
        binary /= 10;
    }
    printf("���: %lld", decimal);

    return 0;
}