#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>

#define xmax 51
#define ymax 51

int mine_count;
int a;
int b;
int c;
int d;
int e;
int founded_mine;
int found;
char visible_board[xmax][ymax];

void input();
void makeboard(char mine_board[xmax][ymax]);
void open(int a, int b, char(*p)[ymax]);
void fail_ending();
void victory_ending();

int main()
{
	//커서 없애는 코드
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	srand(time(NULL));

	input();//입력받는 코드
	char mine_board[xmax][ymax];
	char(*p)[ymax] = mine_board;
	for (int x = 0; x < d; x++)
		for (int y = 0; y < e; y++)
		{
			mine_board[y][x] = '0';//mine_board는 모든 칸을 '0'으로 초기화
			visible_board[y][x] = '@';//visible_board는 모든 칸을 '@'로 초기화
		}
	makeboard(mine_board);//mine_board를 만드는 함수
	for (int i = 0; i < d * e; i++)
	{
		for (int x = 0; x < d; x++)
		{
			for (int y = 0; y < e; y++)
				printf("%c ", mine_board[y][x]);//visible_board 출력
			printf("\n");
		}
		for (int x = 0; x < d; x++)
		{
			for (int y = 0; y < e; y++)
				printf("%c ", visible_board[y][x]);//visible_board 출력
			printf("\n");
		}
		printf("무엇을 하시겠습니까?(1:지뢰에 표시,2:선택) : ");
		scanf("%d", &c);
		switch (c) {//지뢰에 표시를 할 것인지 칸을 선택할 것인지에 따른 코드
		case 1://지뢰에 표시 코드
			printf("선택하려는 칸의 좌표를 입력해주세요(x좌표,y좌표) : ");
			scanf("%d,%d", &a, &b);
			visible_board[a - 1][b - 1] = '#';
			found++;                            //found는 실행자가 표시한 개수
			if (mine_board[a - 1][b - 1] == '*')
				founded_mine++;                 //founded_mined은 실행자가 표시한 것 중 진짜 지뢰가 있는 것의 개수
			if (founded_mine == mine_count && found == founded_mine)//founded_mine, mine_count, found가 같다면 전부 다 찾은 것=승리
				victory_ending();
			break;
		case 2://칸을 선택했을 때
			printf("선택하려는 칸의 좌표를 입력해주세요(x좌표,y좌표) : ");
			scanf("%d,%d", &a, &b);
			open(a, b, p);
			break;
		}
	}
}

void input()//입력받는 함수,
{
	printf("판의 가로칸 개수는?(1~50)");
	scanf("%d", &d);
	printf("판의 세로칸 개수는?(1~50)");
	scanf("%d", &e);
	printf("지뢰의 개수는?");
	scanf("%d", &mine_count);
}

void makeboard(char mine_board[xmax][ymax])
{
	int x, y;
	char count = '0';

	for (int n = 0; n < mine_count; n++)//랜덤하게 지뢰 설치
	{
		x = rand() % d;
		y = rand() % e;
		if (mine_board[y][x] == '0')
			mine_board[y][x] = '*';
		else n--;
	}

	for (int i = 0; i <= e; i++)//지뢰가 없는 칸에는 주변에 지뢰가 몇개인지 표시
	{
		for (int j = 0; j <= d; j++)
		{
			if (mine_board[j][i] != '*')
			{
				if (mine_board[j - 1][i - 1] == '*') count++;
				if (mine_board[j - 1][i] == '*') count++;
				if (mine_board[j - 1][i + 1] == '*') count++;
				if (mine_board[j][i - 1] == '*') count++;
				if (mine_board[j][i + 1] == '*') count++;
				if (mine_board[j + 1][i - 1] == '*') count++;
				if (mine_board[j + 1][i] == '*') count++;
				if (mine_board[j + 1][i + 1] == '*') count++;
				mine_board[j][i] = count;
			}
			count = '0';
		}
	}
}

void fail_ending()
{
	system("cls");
	printf("당신은 지뢰를 밟았습니다.\n당신은 패배했습니다.");
	exit(0);
}

void victory_ending()
{
	system("cls");
	printf("당신은 모든 지뢰를 찾았습니다.\n당신이 승리했습니다.");
	exit(0);
}

void open(int a, int b, char(*p)[ymax])
{
	if ((*(p + a - 1))[b - 1] == '*')//만약 고른 칸이 지뢰라면 패배
	{
		fail_ending();
		exit(0);
	}
	else
		visible_board[a - 1][b - 1] = (*(p + a - 1))[b - 1];//고른 칸이 지뢰가 아니면 mine_board의 값 그대로 가져오기
}
