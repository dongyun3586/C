#include<stdio.h>

int fibonacci(int n);

int main() {
    for (int i = 0; i <= 20; i++)
        printf("fibonacci(%2d) = %d\n", i, fibonacci(i));

    return 0;
}

int fibonacci(int n) {
    if (n < 2)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}