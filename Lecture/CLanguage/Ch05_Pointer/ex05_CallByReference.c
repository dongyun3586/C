#include <stdio.h>

void changeNum_CallByValue(int a) {
    a = 100;
}

void changeNum_CallByReference(int* a) {
    *a = 100;
}

int main()
{
    int a = 0;

    changeNum_CallByValue(a);
    printf("changeNum_CallByValue(a) = %d\n", a);

    changeNum_CallByReference(&a);
    printf("changeNum_CallByReference(&a) = %d\n", a);

    return 0;
}