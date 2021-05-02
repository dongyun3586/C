#include <stdio.h>

void printLine(int n);  // 함수 원형 선언

void main_ex01_function2()
{
    int a, b;

    printf("두 정수의 사칙연산 프로그램\n");
    printLine(30);
    
    printf("\n정수 두 개 입력: ");
    scanf("%d %d", &a, &b);
    printf("\n");

    // add
    printf("%d + %d = %d\n", a, b, a + b);
    printLine(15);

    // subtract
    printf("%d - %d = %d\n", a, b, a - b);
    printLine(15);

    // multiply
    printf("%d * %d = %d\n", a, b, a * b);
    printLine(15);

    // divide
    printf("%d / %d = %.2f\n", a, b, (float)a / b);
    printLine(15);
}

//// 함수 정의
//void printLine(int n) {
//    for (int i = 0; i < n; i++)
//        printf("-");
//    printf("\n");
//}

