#include <stdio.h>

void add(int value1, int value2)         // function definition   
{
    int result = value1 + value2;
    printf("%d + %d = %d\n", value1, value2, result);
}

int subtract(int value1, int value2)         // function definition   
{
    int result = value1 - value2;
    return result;                  // return statement
}

int multiply(int a, int b);

void main()
{
    int a, b, result;

    printf("정수 두 개 입력: ");
    scanf("%d %d", &a, &b);

    add(a, b);        // function call
    result = subtract(a, b);
    printf("%d - %d = %d \n", a, b, result);
    printf("%d * %d = %d \n", a, b, multiply(a, b));
}

int multiply(int a, int b) {
    return a * b;
}