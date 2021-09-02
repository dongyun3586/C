#include <stdio.h>

void swap(int* pa, int* pb) {
    int temp = *pa;
    pa = pb;
    *pb = temp;
}

int main()
{
    int start = 96, end = 5;
    
    printf("before : start = %d, end = %d\n", start, end);
    swap(&start, &end);
    printf("before : start = %d, end = %d\n", start, end);

    return 0;
}