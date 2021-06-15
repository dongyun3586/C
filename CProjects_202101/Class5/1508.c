#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <windows.h>

void print_time(int t, int x);				//시간을 출력해주는 함수
void timer();					//타이머가 작동되는 함수

int times[10][5][4] =				//디지털 숫자를 저장해둔 3차원 배열
{
		{	{1,1,1,1},				//0
			{1,0,0,1},
			{1,0,0,1},
			{1,0,0,1},
			{1,1,1,1}
		},
		{	{0,0,0,1},				//1
			{0,0,0,1},
			{0,0,0,1},
			{0,0,0,1},
			{0,0,0,1}
		},
		{	{1,1,1,1},				//2
			{0,0,0,1},
			{1,1,1,1},
			{1,0,0,0},
			{1,1,1,1}
		},
		{	{1,1,1,1},				//3
			{0,0,0,1},
			{1,1,1,1},
			{0,0,0,1},
			{1,1,1,1}
		},
		{	{1,0,0,1},				//4
			{1,0,0,1},
			{1,1,1,1},
			{0,0,0,1},
			{0,0,0,1}
		},
		{	{1,1,1,1},				//5
			{1,0,0,0},
			{1,1,1,1},
			{0,0,0,1},
			{1,1,1,1}
		},
		{	{1,1,1,1},				//6
			{1,0,0,0},
			{1,1,1,1},
			{1,0,0,1},
			{1,1,1,1}
		},
		{	{1,1,1,1},				//7
			{0,0,0,1},
			{0,0,0,1},
			{0,0,0,1},
			{0,0,0,1}
		},
		{	{1,1,1,1},				//8
			{1,0,0,1},
			{1,1,1,1},
			{1,0,0,1},
			{1,1,1,1}
		},
		{	{1,1,1,1},				//9
			{1,0,0,1},
			{1,1,1,1},
			{0,0,0,1},
			{1,1,1,1}
		},
};

int main()
{
	int timer_key;					//시계를 작동시킬지 타이머를 작동시킬지 저장하는 변수

	printf("\n\n타이머를 작동하고 싶다면 space바, 시계를 작동시키고 싶다면 아무키나 누르세요\n");

	timer_key = getch();			//키를 입력 받음

	if (timer_key == 32)			//스페이스바가 눌리면 타이머 실행
	{
		timer();
		printf("시간이 끝났습니다");
	}
	else if (timer_key != 32)		//스페이스바가 아닌 키가 눌리면 디지털 시계 실행
	{
		system("cls");
		while (1)
		{
			int t;
			t = time(NULL);			//현재 시간(현재까지 흘러온 시간이 초로 저장되어 있음) 저장

			print_time(t, 1);		//시간 출력

			Sleep(1000);
			system("cls");
		}
	}
	return 0;
}

void print_time(int local_t, int x)	//타이머와 시계의 시간을 출력해줌, 여기서 x는 타이머인지 시계인지 판별해줌(0이면 타이머, 1이면 시계)
{
	int hour, min, sec;
	int i, j, k, t = 0, clock[6] = { 0 };

	if (x == 1)						//시계라면 현재 시, 분, 초 계산해주고 저장
	{
		hour = ((local_t / 60) / 60 + 9) % 24;
		min = (local_t / 60) % 60;
		sec = local_t % 60;
	}
	else if (x == 0)				//타이머라면 입력해준 숫자만 시, 분, 초로 계산하고 저장
	{
		sec = local_t % 60;
		min = (local_t / 60) % 60;
		hour = (local_t / 3600);
	}

	if (hour > 12 && x == 1)		//시계라면 오전이라면 t에 0, 오후라면 1을 넣어놓는다.
	{
		t = 1;
		hour = hour - 12;
	}

	clock[0] = hour / 10;			//clock 배열에 출력할 시간 저장
	clock[1] = hour % 10;
	clock[2] = min / 10;
	clock[3] = min % 10;
	clock[4] = sec / 10;
	clock[5] = sec % 10;

	printf("\n\n");

	for (i = 0; i < 5; i++)			//위에서 한줄씩 출력해줌
	{
		for (j = 0; j < 5; j++)		//가독성 위해 시계 앞에 공백 5칸
		{
			if (i == 2 && j == 2 && x == 1)
			{
				if (t == 1)
					printf(" P");	//오후라면 P출력
				else if (t == 0)
					printf(" A");	//오전이라면 A출력
			}
			else if (i == 2 && j == 3 && x == 1)
				printf("M ");
			else
				printf("  ");
		}

		for (j = 0; j < 6; j++)		//clock에 저장해뒀던 수 6개를 출력
		{
			for (k = 0; k < 4; k++)
			{
				if (times[clock[j]][i][k] == 1)
				{
					printf("■");
				}
				else if (times[clock[j]][i][k] == 0)
				{
					printf("  ");
				}
			}

			printf("  ");

			if (j == 1 || j == 3)
			{
				if (i == 1 || i == 3)
				{
					printf("■");
					printf("  ");
				}
				else
				{
					printf("    ");
				}
			}
		}

		printf("\n");
	}
}

void timer()						//타이머 기능하는 함수
{
	system("cls");

	int timer_hour, timer_min, timer_sec, timer_time;

	printf("\n\n타이머 입니다. 시간, 분, 초을 입력해 주세요\n");
	printf("주의)시간은 모두 합쳐서 99시간 59분 59초가 넘으면 안됨\n");
	printf("시간,분,초를 입력하실때는 숫자만 입력해주세요\n\n");
	printf("시간 : ");
	scanf("%d", &timer_hour);

	printf("분 : ");
	scanf("%d", &timer_min);

	printf("초 : ");
	scanf("%d", &timer_sec);

	timer_time = (timer_hour) * 3600 + timer_min * 60 + timer_sec;
	system("cls");

	while (timer_time != 0)			//입력한 시간이 모두 지날때까지 반복
	{
		print_time(timer_time, 0);
		Sleep(1000);
		timer_time--;
		system("cls");
	}
	return 0;
}