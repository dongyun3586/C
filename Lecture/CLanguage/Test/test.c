#include <stdio.h>
#include <myMath.h>

void main()
{
    int a, b;

    printf("���� �� �� �Է�: ");
    scanf("%d %d", &a, &b);

    add(a, b);
    subtract(a, b);
    multiply(a, b);
    divide(a, b);
}