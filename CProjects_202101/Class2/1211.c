#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	//우리 반 친구들 25명의 자리를 무작위로 배열하기
	//우선 7*7 배열로 세팅한 이후 가장 겉부분을 모두 0으로 세팅한다.
	int student[7][7] = { 0,0,0,0,0,0,0,0,1,2,3,4,5,0,0,6,7,8,9,10,0,0,11,12,13,14,15,0,0,16,17,18,19,20,0,0,21,22,23,24,25,0 };
	//우선 원래 자기 번호를 준다.
	int y = 0, x = 0;

	srand(time(NULL));
	for (int i = 0; i < rand() % 100 + 1; i++)
	{
		int sum;//얘는 값을 받아줄 빈공간
		int m1 = rand() % 5 + 1;
		int n1 = rand() % 5 + 1;
		sum = student[m1][n1];
		int m2 = rand() % 5 + 1;
		int n2 = rand() % 5 + 1;
		student[m1][n1] = student[m2][n2];
		student[m2][n2] = sum;
		//이 코드는 무작위로 2개의 수를 선택한 후 서로 값을 바꿈으로써 섞어준다.
	}
	for (y = 1; y < 6; y++)
	{
		for (x = 1; x < 6; x++)
		{
			printf("%02d ", student[y][x]);
		}
		printf("\n"); //7*7중 5*5 배열한 것을 출력해준다.
	}


	//25명 중 2개의 번호를 선택하자.
	int a1 = rand() % 5 + 1;
	int a2 = rand() % 5 + 1;
	int b1 = rand() % 5 + 1;
	int b2 = rand() % 5 + 1;
	//각 번호가 가지고 있는 폭탄의 개수
	int bombnumber[7][7] = { 0 };
	bombnumber[a1][b1] = 1;
	bombnumber[a2][b2] = 1;
	int total = 2; //전체 폭탄개수
A:
	printf("\n");
	printf("난이도를 선택하세요\n\n");
	printf("쉬움:12회--> 1을 입력하세요\n\n");
	printf("보통:9회--> 2을 입력하세요\n\n");
	printf("어려움:6회--> 3을 입력하세요\n\n");

	int num;
	scanf("%d", &num);
	if (num < 1 || num>3)
	{
		printf("다시 입력해주세요.\n");
		goto A;
	}
	int a, sum = 0;//a는 임의의 한 번호, sum은 어떤 한 번호를 선택했을 때 상하좌우에 있는 친구들이 가지고 있는 폭탄 개수의 총합

	if (num == 1)
	{
		int x1, y1;//임의의 번호를 입력했을 때 이 번호의 열을 x1, 행을 y1으로 정의함.
		for (int i = 0; i < 12; i++)
		{
			if (total == 0)//남아있는 폭탄이 0개가 되면 실행종료
			{
				printf("폭탄을 모두 찾았습니다!");
				break;
			}

			printf("번호를 입력하세요:");//y1,x1은 a의 행과 열
			scanf("%d", &a);
			for (y = 1; y < 6; y++)
			{
				for (x = 1; x < 6; x++)
				{
					if (student[y][x] == a)
					{
						x1 = x;
						y1 = y;
					}
				}
			}
			printf("이 학생이 가지고 있는 폭탄의 개수: %d\n", bombnumber[y1][x1]);//a번의 학생이 가지고 있는 폭탄개수
			if (bombnumber[y1][x1] == 1)
			{
				total--;
				bombnumber[y1][x1] = 0;
			}

			sum = bombnumber[y1 - 1][x1] + bombnumber[y1 + 1][x1] + bombnumber[y1][x1 + 1] + bombnumber[y1][x1 - 1];
			printf("이 학생 주변에 존재하는 폭탄의 개수:%d\n", sum);
		}
	}

	else if (num == 2)
	{
		int x1, y1;//임의의 번호를 입력했을 때 이 번호의 열을 x1, 행을 y1으로 정의함.
		for (int i = 0; i < 9; i++)
		{
			if (total == 0)//남아있는 폭탄이 0개가 되면 실행종료
			{
				printf("폭탄을 모두 찾았습니다!");
				break;
			}

			printf("번호를 입력하세요:");//y1,x1은 a의 행과 열
			scanf("%d", &a);
			for (y = 1; y < 6; y++)
			{
				for (x = 1; x < 6; x++)
				{
					if (student[y][x] == a)
					{
						x1 = x;
						y1 = y;
					}
				}
			}
			printf("이 학생이 가지고 있는 폭탄의 개수: %d\n", bombnumber[y1][x1]);//a번의 학생이 가지고 있는 폭탄개수
			if (bombnumber[y1][x1] == 1)
				total--;
			sum = bombnumber[y1 - 1][x1] + bombnumber[y1 + 1][x1] + bombnumber[y1][x1 + 1] + bombnumber[y1][x1 - 1];
			printf("이 학생 주변에 존재하는 폭탄의 개수:%d\n", sum);
			printf("\n");
		}
	}

	else if (num == 3)
	{
		int x1, y1;//임의의 번호를 입력했을 때 이 번호의 열을 x1, 행을 y1으로 정의함.
		for (int i = 0; i < 6; i++)
		{
			if (total == 0)//남아있는 폭탄이 0개가 되면 실행종료
			{
				printf("폭탄을 모두 찾았습니다!");
				break;
			}

			printf("번호를 입력하세요:");//y1,x1은 a의 행과 열
			scanf("%d", &a);
			for (y = 1; y < 6; y++)
			{
				for (x = 1; x < 6; x++)
				{
					if (student[y][x] == a)
					{
						x1 = x;
						y1 = y;
					}
				}
			}
			printf("이 학생이 가지고 있는 폭탄의 개수: %d\n", bombnumber[y1][x1]);//a번의 학생이 가지고 있는 폭탄개수
			if (bombnumber[y1][x1] == 1)
				total--;
			sum = bombnumber[y1 - 1][x1] + bombnumber[y1 + 1][x1] + bombnumber[y1][x1 + 1] + bombnumber[y1][x1 - 1];
			printf("이 학생 주변에 존재하는 폭탄의 개수:%d\n", sum);
		}
	}


}