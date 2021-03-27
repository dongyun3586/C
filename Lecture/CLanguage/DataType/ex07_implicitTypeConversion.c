#include <stdio.h>

int main_ex07_implicitTypeConversion()
{
#pragma region 자료형 확장(type promotion)
    // 1. int와 float 자료형의 연산 결과 => 실수
    int num1 = 11;
    float num2 = 4.4f;

    printf("%f\n", num1 + num2);    // 15.400000: 정수와 실수 덧셈. 정수는 실수로 변환됨
    printf("%f\n", num1 - num2);    // 6.600000: 정수와 실수 뺄셈. 정수는 실수로 변환됨
    printf("%f\n", num1 * num2);    // 48.400002: 정수와 실수 곱셈. 정수는 실수로 변환됨
    printf("%f\n", num1 / num2);    // 2.500000: 정수와 실수 나눗셈. 정수는 실수로 변환됨

    // 2. int와 long long int 자료형의 연산 결과 => long long 형
    long long num3 = 123456789000;
    int num4 = 10;

    printf("%lld\n", num3 + num4);    // 123456789010
    printf("%lld\n", num3 - num4);    // 123456788990
    printf("%lld\n", num3 * num4);    // 1234567890000
    printf("%lld\n", num3 / num4);    // 12345678900
#pragma endregion

#pragma region 자료형 축소(type demotion)
    //// 3. float 자료형값을 int형 변수에 저장 => int형으로 변환됨.
    //float num1 = 11.0f;
    //float num2 = 5.0f;

    //int num3 = num1 / num2;    // 실수에서 실수를 나누어 2.2가 나왔지만 
    //                           // 정수 자료형에는 2만 저장되고 0.2는 버려짐

    //printf("%d\n", num3);    // 2

    //// 4. int 자료형 값을 char 자료형에 저장 => char형으로 변환됨.
    //char num4 = 28;
    //int num5 = 1000000002;

    //char num6 = num4 + num5;    // char보다 큰 숫자는 저장할 수 없음
    //                            // 28 + 2만 남고 앞 자릿수는 버려짐

    //printf("%d\n", num6);    // 30
#pragma endregion

    return 0;
}