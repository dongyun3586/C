#include <stdio.h>

long long lcm(long long  a, long long  b);
long long  multiple = 0;

int main()
{
    long long num1, num2, LCM;

    printf("최소 공배수를 찾을 두 수 입력: ");
    scanf("%lld %lld", &num1, &num2);

    // 이 교환 작업을 안해도 최소공배수는 구해진다. 하지만 반복 횟수가 줄어든다.
    long long temp;
    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    /*if (num1 > num2)
        LCM = lcm(num2, num1);
    else
        LCM = lcm(num1, num2);*/

    //LCM = (num1 > num2) ? lcm(num2, num1) : lcm(num1, num2);

    printf("LCM(%lld, %lld) = %lld\n", num1, num2, lcm(num1, num2));

    return 0;
}

long long lcm(long long a, long long b)
{
    //static int multiple = 0;
    multiple += b;

    // 최소공배수를 찾으면 return
    if ((multiple % a == 0) && (multiple % b == 0))
        return multiple;
    else
        return lcm(a, b);
}