#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define size 19
#define black 1
#define white 2


void gotoxy(int x, int y);        //인터넷에서 따온 좌표계를 설정해주는 함수
void gamelobby();  // 게임로비 함수
void printblack(); // 검은색 돌 출력 함수
void printwhite(); // 흰색 돌 출력 함수
void introducegmae();  // 게임 설명 함수
void field();     // 오목 판 만들어주는 함수
int playgame(int x, int y, int rock); // 게임 실행하는 함수 --> rock 이 1이면 검은색, rock이 2면 흰색, rock에 다른 것이 잘못 입력되었으면 0이 리턴된다.
int process(); // 게임 과정
void input(int* x, int* y); // 좌표를 문자열로 받고 좌표를 넘겨주는 함수. 잘못된 문자열(좌표)가 입력되면 x와 y는 -1로 준다. 인터넷에서 받아옴
void gotoInput(); // 입력받을 좌표로 이동하는 함수
int CheckFinish(int n); // 끝났는지 확인해주는 함수


char n;
char board[19][19];

void gotoxy(int x, int y) {
	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void printblack()
{
	printf("●");
}

void printwhite()
{
	printf("○");
}

void gamelobby()
{
	gotoxy(15, 4); printf("●                              ●●●●●●"); Sleep(430);
	gotoxy(14, 5); printf("●  ●                            ●        ●"); Sleep(430);
	gotoxy(13, 6); printf("●      ●                          ●        ●"); Sleep(430);
	gotoxy(12, 7); printf("●          ●                        ●        ●"); Sleep(430);
	gotoxy(11, 8); printf("●              ●                      ●        ●"); Sleep(430);
	gotoxy(12, 9); printf("●          ●                        ●●●●●●"); Sleep(430);
	gotoxy(13, 10); printf("●      ●                               ●"); Sleep(430);
	gotoxy(14, 11); printf("●  ●                                 ●"); Sleep(430);
	gotoxy(15, 12); printf("●                                   ●"); Sleep(430);
	gotoxy(15, 13); printf("●                           ●●●●●●●●●"); Sleep(430);
	gotoxy(15, 14); printf("●"); Sleep(430);
	gotoxy(10, 15); printf("●●●●●●●●●●●                   ●●●●●●●"); Sleep(430);
	gotoxy(36, 16); printf(" ●"); Sleep(430);
	gotoxy(36, 17); printf(" ●"); Sleep(430);
	gotoxy(36, 18); printf(" ●"); Sleep(430);
	gotoxy(36, 19); printf(" ●"); Sleep(430);
	gotoxy(36, 20); printf(" ●"); Sleep(430);
	gotoxy(14, 22); printf("------------------------------------------");
	gotoxy(14, 23); printf("게임을 시작하고 싶으면 Enter를 눌러주세요.");
	gotoxy(14, 24); printf("------------------------------------------\n\n");
	scanf("%c", &n);
	if (n == '\n');
	introducegmae();
	field();
}

void introducegmae()
{
	gotoxy(17, 60);  printf("안녕하세요. 오목게임에 오신걸 환영합니다. "); Sleep(1500);
	gotoxy(8, 61); printf("오목은 다섯개의 같은 색의 돌이 가로, 세로, 대각선으로 일렬로 이어졌을때 이기는 게임입니다."); Sleep(1500);
	gotoxy(1, 62); printf("검은색 돌은 선공을 하지만 4x3만을 만들 수 있지만 흰색 돌은 6개를 한번에 이어도 승리하고 어느 것을 해도 반칙이 아닙니다."); Sleep(1500);
	gotoxy(17, 63); printf("그러면 재미있게 즐겨주세요. 바로 시작합니다."); Sleep(1500);
	system("cls");
}

void field()
{
	gotoxy(0, 0);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			gotoxy(i, j);
			if (i == 0)
			{
				if (j == 0)
					printf("┌");
				else if (j == size)
					printf("└");
				else
					printf("├");
			}
			else if (i == size - 1)
			{
				if (j == 0)
					printf("┐");
				else if (j == size)
					printf("┘");
				else
					printf("┤");
			}
			else if (j == size - 1)
			{
				if (i == 0)
					printf("┼");
				else if (i == size - 1)
					printf("┼");
				else
					printf("┼");
			}
			else if (j == size)
			{
				if (i == 0)
					continue;
				else if (i == size - 1)
					printf("┼");
				else
					printf("┴");
			}
			else
				printf("┼");
		}
	}
	for (int i = 0; i < size; i++) {
		gotoxy(size, i);
		printf("%d", i + 1);
		gotoxy(i, size);
		printf("%c", i + 'A');
	}
	gotoInput();
	printf("fin.");
	process();
}

int process()
{
	int x = 1, y = 1, z = 1, w = 0;
	for (;;)
	{
		input(&x, &y);
		z += playgame(x, y, z % 2 + 1);
		if (w = CheckFinish(0))
		{
			gotoInput();
			printf("gameover.. ");
			if (w == white)
			{
				printf("black win"), printblack;
			}
			else if (w == black)
			{
				printf("white win"), printwhite;
			}
			break;
		}
	}
	return 0;
}

int playgame(int x, int y, int rock)
{
	if (board[x][y] || x < 0 || x >= size || y < 0 || y >= size)
	{
		rock = 0;
		return 0;
	}
	gotoxy(x, y);

	if (rock == 1)
	{
		printblack(); // rock가 1 이면 검은색 돌
		board[x][y] = black;
	}
	else if (rock == 2)
	{
		printwhite(); // rock가 2면 흰색 돌
		board[x][y] = white;
	}
	else
		return 0;  // rock가 1과 2가 아닌 다른 값이 들어간 경우 0을 리턴
	return 1;    // 제대로 돌이 입력이 된경우 1을 리턴
}

int main()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  // 커서를 숨겨주는 코드

	gamelobby();
}

void input(int* x, int* y) {
	gotoInput();
	printf("Input Coordinate (A19): ");
	char s[10];
	gets_s(s, sizeof(s));
	*x = s[0] - 'A';
	if (strlen(s) > 3)
		return;
	if (strlen(s) == 3)
		*y = (s[1] - '0') * 10 + s[2] - '0' - 1;
	else if (strlen(s) == 2)
		*y = s[1] - '0' - 1;
	else
		*y = *x = -1;
	gotoInput(); printf("Input Coordinate (A19): \t\t\t");
	return;
}

void gotoInput() {
	gotoxy(22, 22);
}



int CheckFinish(int n)
{
	if (n == size * size)
		return 0;
	int y = n / size;
	int x = n % size;
	int stone = board[y][x];
	int arr[5] = { 0 };

	for (int i = 0; i < 5 && stone != 0; i++)
	{
		if (x + i < size && stone == board[y][x + i])
			arr[0]++;
		if (y + i < size && stone == board[y + i][x])
			arr[1]++;
		if (x + i < size && y + i < size && stone == board[y + i][x + i])
			arr[2]++;
	}

	for (int i = 0; i < 3; i++)
		if (arr[i] == 5)
			return stone;
	return CheckFinish(n + 1);
}