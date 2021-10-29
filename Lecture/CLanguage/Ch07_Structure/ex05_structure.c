#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

struct date getTomorrowDate(struct date today);

int main()
{
    struct date today, tomorrow;

    printf("Enter today's date (mm dd yyyy): ");
    scanf("%d %d %d", &today.month, &today.day, &today.year);

    tomorrow = getTomorrowDate(today);
    printf("tomorrow's date is %d/%d/%d\n", tomorrow.month, tomorrow.day, tomorrow.year);

    return 0;
}

// 내일 날짜 반환 함수
struct date getTomorrowDate(struct date today) {
    struct date tomorrow;
    int numberOfDays(struct date d);
    if (today.day != numberOfDays(today)) {     // 월의 마지막날이 아닌 경우
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }
    else if (today.month == 12) {               // 월의 마지막날 && 연도의 마지막날인 경우
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    }
    else {                                      // 월의 마지막날인 경우
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }

    return tomorrow;
}

// 월 일수 반환 함수
int numberOfDays(struct date d)
{
    int isLeapYear(struct date d);

    const int daysPerMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (isLeapYear(d) && d.month == 2)
        return 29;                          // 윤년
    else
        return daysPerMonth[d.month - 1];   // 평년
}

// 윤년 체크 함수
int isLeapYear(struct date d) {
    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
        return 1;    // 윤년
    else
        return 0;    // 평년
}