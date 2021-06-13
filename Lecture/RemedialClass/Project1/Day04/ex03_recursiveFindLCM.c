#include <stdio.h>

int lcm(int a, int b);
int multiple = 0;

int main()
{
    int num1, num2, LCM;

    printf("최소 공배수를 찾을 두 수 입력: ");
    scanf("%d %d", &num1, &num2);

    if (num1 > num2)
        LCM = lcm(num2, num1);
    else
        LCM = lcm(num1, num2);

    printf("LCM(%d, %d) = %d\n", num1, num2, LCM);

    return 0;
}

int lcm(int a, int b)
{
    //static int multiple = 0;
    multiple += b;

    // 최소공배수를 찾으면 return
    if ((multiple % a == 0) && (multiple % b == 0))
        return multiple;
    else
        return lcm(a, b);
}