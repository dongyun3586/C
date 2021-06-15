#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define C 3
#define M 12
void hello();

int main()
{
    printf("1107 김태우\n");
    hello();
    printf("요일을 알고싶은 날짜를 입력해주세요\n");

    int a[C + 1];
    int dal[M + 1] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int sum = 0, i, j;

    for (j = 1; j <= C; j++)
    {
        scanf("%d", &a[j]);
    }

    dal[2] = 28;

    if (a[1] % 4 == 0)
    {
        if (a[1] % 100 == 0)
        {
            if (a[1] % 400 == 0)
            {
                dal[2] = 29;
            }
            else
            {
                dal[2] = 28;
            }
        }
        else
        {
            dal[2] = 29;
        }
    }

    sum += (a[1] - 1) * 365;
    sum += (a[1] - 1) / 4;
    sum -= (a[1] - 1) / 100;
    sum += (a[1] - 1) / 400;

    for (j = 1; j <= a[2] - 1; j++)
    {
        sum += dal[j];
    }
    sum += a[3];

    if (sum % 7 == 1)
        printf("월요일입니다");

    else if (sum % 7 == 2)
        printf("화요일입니다");

    else if (sum % 7 == 3)
        printf("수요일입니다");

    else if (sum % 7 == 4)
        printf("목요일입니다");

    else if (sum % 7 == 5)
        printf("금요일입니다");

    else if (sum % 7 == 6)
        printf("토요일입니다");

    else if (sum % 7 == 0)
        printf("일요일입니다");

    printf("\n");

    if (a[2] == 1 && a[3] == 1)
    {
        printf("신정입니다.");
    }

    if (a[2] == 3 && a[3] == 1)
    {
        printf("삼일절입니다.");
    }

    if (a[2] == 6 && a[3] == 6)
    {
        printf("현충일입니다.");
    }

    if (a[2] == 8 && a[3] == 15)
    {
        printf("광복절입니다.");
    }

    if (a[2] == 10 && a[3] == 3)
    {
        printf("개천절입니다.");
    }

    if (a[2] == 10 && a[3] == 9)
    {
        printf("한글날입니다.");
    }

    if (a[2] == 12 && a[3] == 25)
    {
        printf("크리스마스입니다");
    }

    if (a[2] == 4 && a[3] == 5)
    {
        printf("식목일입니다.");
    }

    if (a[2] == 7 && a[3] == 17)
    {
        printf("제헌절입니다.");
    }

    if (a[2] == 10 && a[3] == 1)
    {
        printf("국군의 날입니다.");
    }

    if (a[2] == 5 && a[3] == 1)
    {
        printf("근로자의 날입니다.");
    }

    if (a[2] == 5 && a[3] == 5)
    {
        printf("어린이날입니다.");
    }

    if (a[2] == 5 && a[3] == 8)
    {
        printf("어버이날입니다.");
    }

    if (a[2] == 5 && a[3] == 15)
    {
        printf("스승의 날입니다.");
    }
    return 0;
}

void hello() {
    printf("*");
    Sleep(300);
    printf("*");
    Sleep(300);
    printf("*");
    Sleep(300);
    printf("요");
    Sleep(300);
    printf("일");
    Sleep(300);
    printf(" 알");
    Sleep(300);
    printf("려");
    Sleep(300);
    printf("주");
    Sleep(300);
    printf("는");
    Sleep(300);
    printf(" 프");
    Sleep(300);
    printf("로");
    Sleep(300);
    printf("그");
    Sleep(300);
    printf("램");
    Sleep(300);
    printf("*");
    Sleep(300);
    printf("*");
    Sleep(300);
    printf("*\n");
    Sleep(300);
}
