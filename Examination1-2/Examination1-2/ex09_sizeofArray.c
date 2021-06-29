#include <stdio.h>
int main()
{
    int numArr[][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
    int r = sizeof(numArr) / sizeof(numArr[0]);
    int c = sizeof(numArr[0]) / sizeof(int);

    printf("%d\n", sizeof(numArr));
    printf("%d\n", sizeof(numArr[0]));
    printf("r=%d, c=%d\n", r, c);

    return 0;
}