#include <stdio.h>
#include "MyMath.h"

void main()
{
    int a, b, result;

    printf("���� �� �� �Է�: ");
    scanf("%d %d", &a, &b);

    add(a, b);
    subtract(a, b);
    multiply(a, b);
    divide(a, b);
}