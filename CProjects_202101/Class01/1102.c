#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX_DAY 100

typedef struct AnniversaryDay
{
	char dayname[20];
	int year;
	int month;
	int day;
}day;

long totalday(int y, int m, int d);

int main(void)
{
	day AnniDay[MAX_DAY];

	int i = 0, total1 = 0, total2 = 0, daynumber = 0, restday = 0;
	int Dy1 = 0, Dm1 = 0, Dd1 = 0;     //기념일의 날짜를 저장
	int Dy2 = 0, Dm2 = 0, Dd2 = 0;     //기준이 되는 오늘의 날짜를 저장
	int importantday[365] = { 0 };
	char wantdayName[20] = { 0 };
	char dayname[365][100] = { 0 };  //기념일의 이름을 저장하는 문자열 이다. 

	printf("이 프로그램은 자신의 중요한 날이나 기념일을 입력하고, \n기념일의 날짜와 그 남은 일 수를 계산하여 출력해 주는 프로그램 입니다.\n");
	printf("입력할 기념일의 갯수를 입력하세요 :");
	scanf("%d", &daynumber);

	for (i = 1; i <= daynumber; i++)  //기념일을 입력받는다.
	{
		printf("\n기념일의 날짜와 기념일의 이름을 입력하세요 (ex) 2021 1 1 생일 :");
		scanf("%d %d %d %s", &AnniDay[i].year, &AnniDay[i].month, &AnniDay[i].day, AnniDay[i].dayname);
	}

	for (i = 1; i <= daynumber; i++)
	{
		printf("%d %d %d %s \n", AnniDay[i].year, AnniDay[i].month, AnniDay[i].day, AnniDay[i].dayname);
	}

	printf("오늘의 날짜를 입력하세요 (ex) 2021 6 1 :");
	scanf("%d %d %d", &Dy2, &Dm2, &Dd2);

	while (true)
	{
		int y, m, d;
		printf("원하는 기념일의 이름을 입력하세요 (종료하려면 \"종료\"를 입력하세요) :");
		scanf("%s", wantdayName);

		if (!strcmp(wantdayName, "종료"))     // 두 문자열이 같은지 비교
		{
			printf("\n종료합니다.");
			break;
		}
		else
		{
			bool bFindOK = false;

			for (i = 1; i <= daynumber; i++)
			{
				if (!strcmp(wantdayName, AnniDay[i].dayname))
				{
					total1 = totalday(AnniDay[i].year, AnniDay[i].month, AnniDay[i].day);
					total2 = totalday(Dy2, Dm2, Dd2);
					if (total1 > total2)
					{
						printf("%d일 남았습니다.\n", total1 - total2);
					}
					if (total1 == total2)
					{
						printf("오늘입니다!\n");
					}
					if (total1 < total2)
					{
						printf("%d일 지났습니다.\n", total2 - total1);
					}
					bFindOK = true;
				}
			}
			if (bFindOK == false)
			{
				printf("잘못 입력하셨습니다.\n");
			}
		}
	}
}

int totalday(int y, int m, int d)
{
	int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sum = 0, j = 0;
	for (j = 0; j < sizeof(months) / sizeof(int); j++)
	{
		sum += months[j];   // sum의 배열의 요소를 더해서 다시 sum에 저장
	}  //굳이 없어도 되는 부분           ->배열의 크기를 계산한다.

	int total = 0;

	total = (y - 1) * 365 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
	{
		months[2]++;       //윤년인 해는 2월에 하루를 추가! 28일->29일
	}
	for (j = 0; j < m - 1; j++)
	{
		total += months[j];
	}

	total += d;
	return total;
}