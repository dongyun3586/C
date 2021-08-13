#include <stdio.h>

int main()
{
    int a = 100;
    float b = 3.14f;
    int* p1 = &a;
    float* p2 = &b;

    printf("a: %d\n", a);
    printf("p: %p\n", p1);
    printf("*p1: %d\n", *p1);
    *p1 += 100;
    printf("*p1: %d\n\n", *p1);

    printf("b: %f\n", b);
    printf("p: %p\n", p2);
    printf("*p2: %f\n", *p2);
    *p2 *= 100;
    printf("*p2: %f\n\n", *p2);

    return 0;
}