#include<stdio.h>
int fibonacci(int n);
int main() {
    for (int i = 1; i <= 10; i++)
        printf("fibonacci(%2d) = %d\n", i, fibonacci(i));
    return 0;
}

int fibonacci(int n) {
    if (n == 0 || n == 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}