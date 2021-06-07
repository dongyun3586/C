#include<stdio.h>

int fibonacci(int n);

int main() {

    for (int i = 0; i <= 20; i++)
        printf("fibonacci(%2d) = %d\n", i, fibonacci(i));

    return 0;
}

int fibonacci(int n) {
    // 종료 조건
    if (n == 0 || n == 1)
        return n;

    // 재귀 호출
    return fibonacci(n - 1) + fibonacci(n - 2);
}