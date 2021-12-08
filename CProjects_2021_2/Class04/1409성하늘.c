#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//숫자 출력
void Print(int n)
{
	switch (n)
	{
	case 0:
		printf("  ");
		break;
	case 1:
		printf("①");
		break;
	case 2:
		printf("②");
		break;
	case 3:
		printf("③");
		break;
	case 4:
		printf("④");
		break;
	case 5:
		printf("⑤");
		break;
	case 6:
		printf("⑥");
		break;
	case 7:
		printf("⑦");
		break;
	case 8:
		printf("⑧");
		break;
	case 9:
		printf("●");
		break;
	}
}

//콘솔창에 좌표값 지정해주기
void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//게임 첫 세팅
void Board(int n, int m)	//가로 m, 세로 n
{
	printf("  ");

	for (int i = 0; i < m; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (i % 2) + 5);
		printf("%2d", i + 1);
	}
	printf("\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	for (int i = 0; i < n; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (i % 2) + 5);
		printf("%2d", i + 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		for (int k = 0; k < m; k++)
			printf("■");
		printf("\n");
	}
}

//시작화면
void Main()
{
	//printf("□□□□□□□□□□■□□□□□□□□□□□□■□□□□□□■□□□□□■□□□□□□□□□□□□■\n");
	//printf("■■■■■■■■■□■□□□■■■■■■■□□■□□□■■■■■■■□□■□□□□■■■■■■□□■\n");
	//printf("□□□□■□□□□□■□□□□□□□□□■□□■□□□□□□■□□□□□■■□□□□□□□□■□□■\n");
	//printf("□□□■□■□□□□■□□□■■■■■■■□□■□□□□□■□■□□□□■□□□□□□□□□■□□■\n");
	//printf("□□■□□□■□□□■□□□■□□□□□□□□■□□□□■□□□■□□□■□□□□□□□□□■□□■\n");
	//printf("□■□□□□□■□□■□□□■■■■■■■□□■□□□□□□□□□□□□■□□□□□□□□□■□□■\n");
	//printf("■□□□□□□□■□■□□□□□□■□□□□□■□□□□□■■■■■■■□□□□□□□□□□■□□■\n");
	//printf("□□□□□□□□□□■□□□□□□■□□□□□■□□□□□□□□■□□□□□□□□□□□□□□□□■\n");
	//printf("□□□□□□□□□□■□□■■■■■■■■■■■□□□□□□□■□■□□□□□□□□□□□□□□□■\n");
	//printf("□□□□□□□□□□□□□□□□□□□□□□□■□□□□□□■□□□■□□□□□□□□□□□□□□□\n");

	int title[10][52] = {
0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
1,1,1,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,1,1,0,0,1,0,0,0,1,1,1,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1,1,0,0,1,0,0,
0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,
0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,
0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,
0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,
1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,
0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	for (int i = 0; i < 10; i++)
	{
		gotoxy(9, 5 + i);
		for (int j = 0; j < 52; j++)
		{
			if (title[i][j] == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);	//검은색으로 안보이게 출력
				printf("■");
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//흰색으로 보이게 출력
				printf("■");
			}
		}
		printf("\n");
	}
}

//시작화면 밑 선택창
int Menu()
{
	int key;
	int x = 55, y = 20;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(x - 2, y);
	printf("> 게임 시작");
	gotoxy(x, y + 1);
	printf("게임 설명");
	gotoxy(x + 2, y + 2);
	printf("종료");

	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 72:
				{
					if (y > 20)
					{
						gotoxy(x - 2, y);
						printf(" ");
						gotoxy(x - 2, --y);
						printf(">");
					}
					break;
				}

				case 80:
				{
					if (y < 22)
					{
						gotoxy(x - 2, y);
						printf(" ");
						gotoxy(x - 2, ++y);
						printf(">");
					}
					break;
				}
				}
			}
			else
			{
				if (key == 13)
					return y - 20;
			}
		}
	}
}

//레벨 선택창
int Level()
{
	int key = 0;
	int x = 10, y = 10;
	gotoxy(x - 2, y);
	printf("> 초급");
	gotoxy(x, y + 1);
	printf("중급");
	gotoxy(x, y + 2);
	printf("고급");

	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 72:
				{
					if (y > 10)
					{
						gotoxy(x - 2, y);
						printf(" ");
						gotoxy(x - 2, --y);
						printf(">");
					}
					break;
				}

				case 80:
				{
					if (y < 12)
					{
						gotoxy(x - 2, y);
						printf(" ");
						gotoxy(x - 2, ++y);
						printf(">");
					}
					break;
				}
				}
			}
			else
			{
				if (key == 13)
					return y - 10;
			}
		}
	}
}

int c[16][30] = { 0 };	//0일때는 열리지 않은 것, 1일때는 열린 것, 2일때는 깃발이 꽂힌것

void Check(int x, int y, int n, int m, int k, int mine[][30])	//가로 n, 세로 m
{
	if (k == 5)
		return 0;
	if (mine[y][x] != 9 && c[y][x] == 0)	//폭탄 아닌 곳, 확인 안 한곳
	{
		k++;
		gotoxy(2 * x + 2, y + 1);
		Print(mine[y][x]);
		c[y][x] = 1;

		if (y > 0) Check(x, y - 1, n, m, k, mine);
		Check(x, y, n, m, k, mine);
		if (y + 1 < m) Check(x, y + 1, n, m, k, mine);
		if (x > 0)
		{
			if (y > 0) Check(x - 1, y - 1, n, m, k, mine);
			Check(x - 1, y, n, m, k, mine);
			if (y + 1 < m) Check(x - 1, y + 1, n, m, k, mine);
		}
		if (x + 1 < n)
		{
			if (y > 0) Check(x + 1, y - 1, n, m, k, mine);
			Check(x + 1, y, n, m, k, mine);
			if (y + 1 < m) Check(x + 1, y + 1, n, m, k, mine);
		}
	}
	else if (mine[y][x] == 9 && k == 0)	//폭탄 설치된 곳 열려고 할 때, 처음 판정일 때
	{
		system("cls");
		gotoxy(0, 0);
		printf("지뢰를 선택했습니다!\n");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				Print(mine[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
}


void Game(int n, int m, int mi) //가로 n 세로 m
{
	int mine[16][30];
	int d = mi;	//지뢰 남은 개수 표시하기
	int x = 0, y = 0, f = 0;	//x,y는 좌표, f는 0일때 열기, 1일때 깃발 꽂기, 2일때 깃발 빼기
	srand(time(NULL));
	for (int i = 0; i < mi; i++)
	{
		x = rand() % n;
		y = rand() % m;
		if (mine[y][x] == 9)
			i--;
		else
			mine[y][x] = 9;
	}

	int count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mine[i][j] != 9)
			{
				if ((i - 1) >= 0)	//현재 위치보다 윗 행 3개 지뢰인지 판단
				{
					if ((j - 1) >= 0 && mine[i - 1][j - 1] == 9) count++;
					if (mine[i - 1][j] == 9) count++;
					if ((j + 1) < n && mine[i - 1][j + 1] == 9) count++;
				}

				if ((j - 1) >= 0 && mine[i][j - 1] == 9) count++;
				if ((j + 1) < n && mine[i][j + 1] == 9) count++;

				if ((i + 1) < m)	//현재 위치보다 아래 행 3개 지뢰인지 판단
				{
					if ((j - 1) >= 0 && mine[i + 1][j - 1] == 9) count++;
					if (mine[i + 1][j] == 9) count++;
					if ((j + 1) < n && mine[i + 1][j + 1] == 9) count++;
				}

				mine[i][j] = count;
				count = 0;
			}
		}
	}

	Board(m, n);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	//흰색으로 출력

	gotoxy(2 * n + 3, 5);
	printf("남은 ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("▶");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("의 개수");
	gotoxy(2 * n + 5, 6);
	printf("%4d", d);

	while (1)
	{
		int k = 0;
		gotoxy(0, m + 2);
		printf("좌표를 입력하세요\n");
		gotoxy(0, m + 4);
		printf("숫자를 입력하세요\n열기:0    깃발 꽂기:1    깃발 빼기:2\n");
		gotoxy(0, m + 3);
		scanf("%d %d", &x, &y);
		if (x > n || y > m || x < 1 || y < 1)
		{
			gotoxy(0, m + 3);
			printf("범위 이내의 값을 입력해주세요");
			Sleep(1000);
			gotoxy(0, m + 3);
			printf("                                                        ");
			continue;
		}
		gotoxy(0, m + 6);
		scanf("%d", &f);
		switch (f)
		{
		case 0:	//열기
			Check(x - 1, y - 1, n, m, k, mine);
			break;
		case 1:	//깃발 꽂기
			if (c[y - 1][x - 1] == 0)	//확인되지 않은 곳
			{
				gotoxy(2 * x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("▶");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				c[y - 1][x - 1] = 2;
				d--;	//깃발 개수 감소
				gotoxy(2 * n + 5, 6);
				printf("%4d", d);
			}
			else
			{
				gotoxy(0, m + 6);
				printf("이미 열리거나 깃발이 꽂아져 있습니다. 다시 입력해주세요");
				Sleep(1000);
				gotoxy(0, m + 6);
				printf("                                                        ");
				gotoxy(0, m + 6);
			}
			break;
		case 2:	//깃발 빼기
			if (c[y - 1][x - 1] == 2)	//깃발이 꽂아진 곳일때
			{
				gotoxy(2 * x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("■");
				c[y - 1][x - 1] = 0;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				d++;	//깃발 개수 추가
				gotoxy(2 * n + 5, 6);
				printf("%4d", d);

			}
			else
			{
				gotoxy(0, m + 6);
				printf("깃발이 없습니다. 다시 입력해주세요");
				Sleep(1000);
				gotoxy(0, m + 6);
				printf("                                                        ");
			}
		default:	//f의 값이 0,1,2 이외의 수 일때 다시 입력받기
		{
			gotoxy(0, m + 6);
			printf("지정되지 않은 값입니다. 다시 입력해주세요");
			Sleep(1000);
			gotoxy(0, m + 6);
			printf("                                                        ");
		}
		break;
		}
		int finish = 0;	//finish 가 0이어야 게임이 끝남->n*m 배열 c의 값에 0이 없어야 함.
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (c[i][j] == 0)
					finish = 1;
			}
		}
		if (finish == 0)
		{
			system("cls");
			printf("축하드립니다. 게임을 클리어 하셨습니다!");
			return 0;
		}
		gotoxy(0, m + 3);
		printf("         ");
		gotoxy(0, m + 6);
		printf("         ");
	}

}

int main() {
	system("mode con cols=120 lines=30"); //콘솔창의 크기 지정
choose:
	system("cls");
	Main();
	int menu = Menu();
	int mine[16][30] = { 0 };
	int key = 0;
	system("cls");
	if (menu == 0)	//게임 시작
	{
		int level = Level();
		system("cls");
		if (level == 0)	//초급 9*9, 지뢰 10개
		{
			Game(9, 9, 10);
		}
		else if (level == 1)	//중급 16*16 지뢰 40개
		{
			Game(16, 16, 40);
		}
		else if (level == 2)	//고급 16*30 지뢰 99개
		{
			Game(30, 16, 99);
		}
	}
	else if (menu == 1)	//게임 설명
	{
		system("cls");
		printf("난이도는 초급, 중급, 고급이 있다\n");
		printf("\n");
		printf("-초급 9 * 9, 지뢰 10개\n");
		printf("-중급 16 * 16 지뢰 40개\n");
		printf("-고급 30 * 16 지뢰 99개\n\n\n");
		printf("1.입력은 좌표로 받으며 가로축 세로축 순으로 입력한다.\n");
		printf("2.칸을 열기를 원한다면 0, 깃발을 꽂고 싶다면 1, 깃발을 빼고 싶으면 2를 입력한다.\n");
		printf("3.만약 지뢰가 있는 칸을 열게 되면 게임은 자동으로 끝이난다.\n");
		printf("4.지뢰를 제외한 모든 칸을 열고 지뢰인 부분에 모두 깃발을 꽂았을 때 이겼다고 판정이 된다.\n\n\n");
		printf("되돌아 가려면 엔터키를 눌러주세요.");

		while (1)
		{
			if (_kbhit())
			{
				key = _getch();
				if (key == 13)
					goto choose;
			}
		}
	}
	else	//게임 종료
	{
		return 0;
	}
}