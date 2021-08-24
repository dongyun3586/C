#include <stdio.h>

// calculator( )함수 선언
void calcuator(int a, int b, int* sum, int* sub, int* mul, float* div);

int main()
{
    int a, b;
    int sum, subtract, multiply;
    float divide;

    printf("양의 정수 두 개 입력: ");
    scanf("%d%d", &a, &b);

    // calculator( ) 함수 호출
    printf("%d + %d = %d\n", a, b, sum);
    printf("%d - %d = %d\n", a, b, subtract);
    printf("%d * %d = %d\n", a, b, multiply);
    printf("%d / %d = %f\n", a, b, divide);

    return 0;
}

// calculator( ) 함수 정의