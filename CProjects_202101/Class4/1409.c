#include<stdio.h>
#include<Windows.h>

//콘솔창에 좌표값 지정해주기
void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//승부의 여부 판단
int Check(char a[20][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			//가로
			if (a[i][j] == 'b' && a[i + 1][j] == 'b' && a[i + 2][j] == 'b' && a[i + 3][j] == 'b' && a[i + 4][j] == 'b')
			{
				system("cls");
				gotoxy(21, 21);
				printf("검은색 팀 우승!\n");
				return 0;
			}
			if (a[i][j] == 'w' && a[i + 1][j] == 'w' && a[i + 2][j] == 'w' && a[i + 3][j] == 'w' && a[i + 4][j] == 'w')
			{
				system("cls");
				gotoxy(21, 21);
				printf("흰색 팀 우승!\n");
				return 0;
			}
			//세로
			if (a[i][j] == 'b' && a[i][j + 1] == 'b' && a[i][j + 2] == 'b' && a[i][j + 3] == 'b' && a[i][j + 4] == 'b')
			{
				system("cls");
				gotoxy(21, 21);
				printf("검은색 팀 우승!\n");
				return 0;
			}
			if (a[i][j] == 'w' && a[i][j + 1] == 'w' && a[i][j + 2] == 'w' && a[i][j + 3] == 'w' && a[i][j + 4] == 'w')
			{
				system("cls");
				gotoxy(21, 21);
				printf("흰색 팀 우승!\n");
				return 0;
			}
			//대각선(오)
			if (a[i][j] == 'b' && a[i + 1][j + 1] == 'b' && a[i + 2][j + 2] == 'b' && a[i + 3][j + 3] == 'b' && a[i + 4][j + 4] == 'b')
			{
				system("cls");
				gotoxy(21, 21);
				printf("검은색 팀 우승!\n");
				return 0;
			}
			if (a[i][j] == 'w' && a[i + 1][j + 1] == 'w' && a[i + 2][j + 2] == 'w' && a[i + 3][j + 3] == 'w' && a[i + 4][j + 4] == 'w')
			{
				system("cls");
				gotoxy(21, 21);
				printf("흰색 팀 우승!\n");
				return 0;
			}
			///대각선(왼)
			if (a[i][j] == 'b' && a[i - 1][j + 1] == 'b' && a[i - 2][j + 2] == 'b' && a[i - 3][j + 3] == 'b' && a[i - 4][j + 4] == 'b')
			{
				system("cls");
				gotoxy(21, 21);
				printf("검은색 팀 우승!\n");
				return 0;
			}
			if (a[i][j] == 'w' && a[i - 1][j + 1] == 'w' && a[i - 2][j + 2] == 'w' && a[i - 3][j + 3] == 'w' && a[i - 4][j + 4] == 'w')
			{
				system("cls");
				gotoxy(21, 21);
				printf("흰색 팀 우승!\n");
				return 0;
			}
		}
	}
}

//게임 첫 세팅
void Board()
{
	gotoxy(0, 0);
	for (int i = 0; i < 20; i++)
	{
		for (int k = 0; k < 20; k++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("■");
		}
		printf("\n");
	}
	gotoxy(50, 10);
	printf("(0,0)~(19,19)사이의 좌표를 입력하세요.");
}

//흰색 돌 원하는 좌표에 출력
void White(int x, int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy((2 * x), y);
	printf("●");
}

//검은색 돌 원하는 좌표에 출력
void Black(int x, int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy((2 * x), y);
	printf("○");
}

int main()
{
	int n = 0, x, y; //어떤 팀의 차례인지 판단할 때 사용, 좌표 입력받을 변수 2개
	char a[20][20] = { 0 }; //승부의 여부 판단할 때 사용

	system("mode con cols=100 lines=22"); //콘솔창의 크기 지정

	//3초후에 시작!
	for (int i = 3; i > 0; i--)
	{
		gotoxy(20, 10);
		printf("Start in %d", i);
		Sleep(1000); //1초간 대기
		system("cls"); //콘솔창 전부 지우기
	}

	//바둑판 생성
	Board();

	//바둑돌 놓기
	while (1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //콘솔창에서 글씨 색깔 흰색으로 설정
		gotoxy(50, 13);
		printf("          ");
		gotoxy(50, 12);
		if (n % 2 == 1)
			printf(">>>>>>>흰 색 팀의 차례입니다<<<<<<<");
		else
			printf(">>>>>>검은 색 팀의 차례입니다<<<<<<");
		gotoxy(50, 13);
		scanf("%d %d", &x, &y);
		while (a[x][y] != 0) //이미 바둑돌이 놓인 곳에 다시 넣으려고 할 때 다시 입력하라고 알려주기
		{
			gotoxy(50, 12);
			if (n % 2 == 1)
				printf(">>>>>>>흰 색 팀 다시 하세요<<<<<<<");
			if (n % 2 == 0)
				printf(">>>>>>>검은 색 팀 다시 하세요<<<<<");
			gotoxy(50, 13);
			printf("       ");
			gotoxy(50, 13);
			scanf("%d %d", &x, &y);
		}

		//바둑돌이 아무것도 없는 곳에 놓일 경우
		if (n % 2 == 1)
		{
			White(x, y); //흰 바둑돌 놓기
			a[x][y] = 'w';
			if (Check(a) == 0) //승부 판정
				break;
		}
		if (n % 2 == 0)
		{
			Black(x, y); //검은 바둑돌 놓기
			a[x][y] = 'b';
			if (Check(a) == 0) // 승부 판정
				break;
		}
		n++;
	}
}