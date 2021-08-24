#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int calculator(int a, int b, int(*calcFunc)(int, int)) {
    return calcFunc(a, b);
}

int main()
{
    int a = 3, b = 4;
    
    printf("Че: %d\n", calculator(a, b, sum));
    printf("Тї: %d\n", calculator(a, b, subtract));

    return 0;
}