#include <stdio.h>

// int sum(int value1, int value2);     // 함수 원형 선언

int sum(int value1, int value2)         // function definition   
{
    int result = value1 + value2;
    return result;                  // return statement
}

void main()
{
    int s;
    s = sum(2, 3);        // function call
    printf("더하기 작업의 결과는 %d \n", s);
}