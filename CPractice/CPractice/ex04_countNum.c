#include <stdio.h>

int main() {
    int number, count = 0;  // INT_MAX = 2,147,483,647

    printf("양의 정수를 입려하시오: ");
    scanf("%d", &number);

    // while문을 사용하여 정수의 자릿수 구하기
    while (number != 0) {
        number /= 10;
        count++;
    }
    printf("자릿수: %d \n", count);

    printf("양의 정수를 입려하시오: ");
    scanf("%d", &number);
    // for문을 사용하여 정수의 자릿수 구하기
    for (count = 0; number != 0; number /= 10)
        count++;

    printf("자릿수: %d \n", count);
}