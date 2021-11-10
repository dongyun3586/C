#include <stdio.h>
int num = 100;
int returnSquare() {
    return num * num;
}
int main()
{
    int num = 200;
    printf("%d\n", returnSquare());
    {
        int num = 300;
        printf("%d\n", num);
    }
    printf("%d\n", num);
    return 0;
}