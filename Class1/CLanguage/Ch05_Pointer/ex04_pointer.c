#include <stdio.h>

int main()
{
    int num = 100;
    int* p = &num;

    printf("num = %d, p = %p, *p=%d\n", num, p, *p);
    (*p)++;
    printf("num = %d, p = %p, *p=%d\n", num, p, *p);

    printf("num = %d, p = %p, *p=%d\n", num, p, *p);
    *p++;
    printf("num = %d, p = %p, *p=%d\n", num, p, *p);

    return 0;
}