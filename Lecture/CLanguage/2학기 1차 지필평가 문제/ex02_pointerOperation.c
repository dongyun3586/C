#include <stdio.h>

int main()
{
    void* p0 = (void*)0;
    char* p1 = (char*)0;
    int* p2 = (int*)0;
    int(*p3)[10] = (int*)0;
    double* p4 = (double*)0;

    p1++;
    p2++;
    p3++;
    p4++;
    printf("p0 = %p\n", p0);
    printf("p1 = %p\n", p1);
    printf("p2 = %p\n", p2);
    printf("p3 = %p\n", p3);
    printf("p4 = %p\n", p4);

    return 0;
}