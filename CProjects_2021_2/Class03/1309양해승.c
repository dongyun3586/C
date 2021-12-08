#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>

int mine_count;
int xmax;
int ymax;
int a;
int b;
int c;
int founded_mine;
int found;
char visible_board[51][51];

void input();
void makeboard(char mine_board[xmax][ymax], char* p);
void open(int a, int b, char* p);
void fail_ending();
void victory_ending();

int main()
{
	//Ŀ�� ���ִ� �ڵ�
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	srand(time(NULL));

	input();//�Է¹޴� �ڵ�
	char mine_board[xmax + 1][ymax + 1];
	char* p = &mine_board[0][0];
	for (int x = 0; x < xmax; x++)
		for (int y = 0; y < ymax; y++)
		{
			mine_board[x][y] = '0';//mine_board�� ��� ĭ�� '0'���� �ʱ�ȭ
			visible_board[y][x] = '@';//visible_board�� ��� ĭ�� '@'�� �ʱ�ȭ
		}
	makeboard(mine_board, p);//mine_board�� ����� �Լ�
	for (int i = 0; i < xmax * ymax - mine_count; i++)
	{
		system("cls");//â û��
		for (int x = 0; x < xmax; x++)
		{
			for (int y = 0; y < ymax; y++)
				printf("%c ", visible_board[y][x]);//visible_board ���
			printf("\n");
		}
		printf("������ �Ͻðڽ��ϱ�?(1:���ڿ� ǥ��,2:����) : ");
		scanf("%d", &c);
		switch (c) {//���ڿ� ǥ�ø� �� ������ ĭ�� ������ �������� ���� �ڵ�
		case 1://���ڿ� ǥ�� �ڵ�
			printf("�����Ϸ��� ĭ�� ��ǥ�� �Է����ּ���(x��ǥ,y��ǥ) : ");
			scanf("%d,%d", &a, &b);
			visible_board[b - 1][a - 1] = '#';
			found++;                            //found�� �����ڰ� ǥ���� ����
			if (mine_board[b - 1][a - 1] == '*')
				founded_mine++;                 //founded_mined�� �����ڰ� ǥ���� �� �� ��¥ ���ڰ� �ִ� ���� ����
			if (founded_mine == mine_count && found == founded_mine)//founded_mine, mine_count, found�� ���ٸ� ���� �� ã�� ��=�¸�
				victory_ending();
			break;
		case 2://ĭ�� �������� ��
			printf("�����Ϸ��� ĭ�� ��ǥ�� �Է����ּ���(x��ǥ,y��ǥ) : ");
			scanf("%d,%d", &a, &b);
			open(a, b, p);
			break;
		}
	}
}

void input()//�Է¹޴� �Լ�,
{
	printf("���� ����ĭ ������?(1~50)");
	scanf("%d", &ymax);
	printf("���� ����ĭ ������?(1~50)");
	scanf("%d", &xmax);
	printf("������ ������?");
	scanf("%d", &mine_count);
}

void makeboard(char mine_board[xmax][ymax], char* p)
{
	int x, y = 0;
	char count = '0';

	for (int n = 0; n < mine_count; n++)//�����ϰ� ���� ��ġ
	{
		x = rand() % ymax;
		y = rand() % xmax;
		if (mine_board[x][y] == '0')
			mine_board[x][y] = '*';
		else n--;
	}

	for (int i = 0; i <= xmax; i++)//���ڰ� ���� ĭ���� �ֺ��� ���ڰ� ����� ǥ��
		for (int j = 0; j <= ymax; j++)
		{
			if (*(p + j + ymax * i) != '*')
			{
				if (*(p + j + ymax * i - ymax - 2) == '*') count++;
				if (*(p + j + ymax * i - ymax - 1) == '*') count++;
				if (*(p + j + ymax * i - ymax) == '*') count++;
				if (*(p + j + ymax * i - 1) == '*') count++;
				if (*(p + j + ymax * i + 1) == '*') count++;
				if (*(p + j + ymax * i + ymax) == '*') count++;
				if (*(p + j + ymax * i + ymax + 1) == '*') count++;
				if (*(p + j + ymax * i + ymax + 2) == '*') count++;
				mine_board[i][j] = count;
			}
			count = '0';
		}
}

void fail_ending()
{
	system("cls");
	printf("����� ���ڸ� ��ҽ��ϴ�.\n����� �й��߽��ϴ�.");
	exit(0);
}

void victory_ending()
{
	system("cls");
	printf("����� ��� ���ڸ� ã�ҽ��ϴ�.\n����� �¸��߽��ϴ�.");
	exit(0);
}

void open(int a, int b, char* p)
{
	if (*(p + a - 1 + (b - 1) * xmax) == '*')//���� �� ĭ�� ���ڶ�� �й�
	{
		fail_ending();
		exit(0);
	}
	else
		visible_board[a - 1][b - 1] = *(p + a - 1 + (b - 1) * xmax);//�� ĭ�� ���ڰ� �ƴϸ� mine_board�� �� �״�� ��������
}
