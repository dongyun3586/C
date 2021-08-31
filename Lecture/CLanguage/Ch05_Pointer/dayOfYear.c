#include<stdio.h>

static int daytab[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int* pmonth, int* pday);

int main(void)
{
    int y, m, d;
    printf("년, 월, 일로부터 연초부터 몇일이 지났는지 구하기\n");
    printf("년, 월, 일 입력(예: 2021 9 1): ");
    scanf("%d %d %d", &y, &m, &d);

    printf("%d\n", day_of_year(y, m, d));

    printf("년, 연초부터 지난 날수로 월, 일 구하기\n");
    printf("년, 연초부터 지난 날수 입력(예: 2021 100): ");
    scanf("%d %d", &y, &d);

    month_day(y, d, &m, &d);
    printf("%d년 %d월 %d일", y, m, d);

    return 0;
}

/* day_of_year: set day of year from month and day */
int day_of_year(int year, int month, int day)
{
    int leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (month < 1 || month > 12)
        return -1;
    if (day < 1 || day > daytab[leap][month])
        return -1;

    for (int i = 1; i < month; i++)
        day += daytab[leap][i];

    return day;
}

/* month_day: set month,day from day of the year */
void month_day(int year, int yearday, int* pmonth, int* pday)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    for (i = 1; i <= 12 && yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    if (i > 12 && yearday > 31)
    {
        *pmonth = -1;
        *pday = -1;
    }
    else
    {
        *pmonth = i;
        *pday = yearday;
    }
}
