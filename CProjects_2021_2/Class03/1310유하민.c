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
	//Ŀ�� ���ִ� �ڵ�
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	srand(time(NULL));

	input();//�Է¹޴� �ڵ�
	char mine_board[xmax][ymax];
	char(*p)[ymax] = mine_board;
	for (int x = 0; x < d; x++)
		for (int y = 0; y < e; y++)
		{
			mine_board[y][x] = '0';//mine_board�� ��� ĭ�� '0'���� �ʱ�ȭ
			visible_board[y][x] = '@';//visible_board�� ��� ĭ�� '@'�� �ʱ�ȭ
		}
	makeboard(mine_board);//mine_board�� ����� �Լ�
	for (int i = 0; i < d * e; i++)
	{
		for (int x = 0; x < d; x++)
		{
			for (int y = 0; y < e; y++)
				printf("%c ", mine_board[y][x]);//visible_board ���
			printf("\n");
		}
		for (int x = 0; x < d; x++)
		{
			for (int y = 0; y < e; y++)
				printf("%c ", visible_board[y][x]);//visible_board ���
			printf("\n");
		}
		printf("������ �Ͻðڽ��ϱ�?(1:���ڿ� ǥ��,2:����) : ");
		scanf("%d", &c);
		switch (c) {//���ڿ� ǥ�ø� �� ������ ĭ�� ������ �������� ���� �ڵ�
		case 1://���ڿ� ǥ�� �ڵ�
			printf("�����Ϸ��� ĭ�� ��ǥ�� �Է����ּ���(x��ǥ,y��ǥ) : ");
			scanf("%d,%d", &a, &b);
			visible_board[a - 1][b - 1] = '#';
			found++;                            //found�� �����ڰ� ǥ���� ����
			if (mine_board[a - 1][b - 1] == '*')
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
	scanf("%d", &d);
	printf("���� ����ĭ ������?(1~50)");
	scanf("%d", &e);
	printf("������ ������?");
	scanf("%d", &mine_count);
}

void makeboard(char mine_board[xmax][ymax])
{
	int x, y;
	char count = '0';

	for (int n = 0; n < mine_count; n++)//�����ϰ� ���� ��ġ
	{
		x = rand() % d;
		y = rand() % e;
		if (mine_board[y][x] == '0')
			mine_board[y][x] = '*';
		else n--;
	}

	for (int i = 0; i <= e; i++)//���ڰ� ���� ĭ���� �ֺ��� ���ڰ� ����� ǥ��
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
	printf("����� ���ڸ� ��ҽ��ϴ�.\n����� �й��߽��ϴ�.");
	exit(0);
}

void victory_ending()
{
	system("cls");
	printf("����� ��� ���ڸ� ã�ҽ��ϴ�.\n����� �¸��߽��ϴ�.");
	exit(0);
}

void open(int a, int b, char(*p)[ymax])
{
	if ((*(p + a - 1))[b - 1] == '*')//���� �� ĭ�� ���ڶ�� �й�
	{
		fail_ending();
		exit(0);
	}
	else
		visible_board[a - 1][b - 1] = (*(p + a - 1))[b - 1];//�� ĭ�� ���ڰ� �ƴϸ� mine_board�� �� �״�� ��������
}
