#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define size 19
#define black 1
#define white 2


void gotoxy(int x, int y);        //���ͳݿ��� ���� ��ǥ�踦 �������ִ� �Լ�
void gamelobby();  // ���ӷκ� �Լ�
void printblack(); // ������ �� ��� �Լ�
void printwhite(); // ��� �� ��� �Լ�
void introducegmae();  // ���� ���� �Լ�
void field();     // ���� �� ������ִ� �Լ�
int playgame(int x, int y, int rock); // ���� �����ϴ� �Լ� --> rock �� 1�̸� ������, rock�� 2�� ���, rock�� �ٸ� ���� �߸� �ԷµǾ����� 0�� ���ϵȴ�.
int process(); // ���� ����
void input(int* x, int* y); // ��ǥ�� ���ڿ��� �ް� ��ǥ�� �Ѱ��ִ� �Լ�. �߸��� ���ڿ�(��ǥ)�� �ԷµǸ� x�� y�� -1�� �ش�. ���ͳݿ��� �޾ƿ�
void gotoInput(); // �Է¹��� ��ǥ�� �̵��ϴ� �Լ�
int CheckFinish(int n); // �������� Ȯ�����ִ� �Լ�


char n;
char board[19][19];

void gotoxy(int x, int y) {
	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void printblack()
{
	printf("��");
}

void printwhite()
{
	printf("��");
}

void gamelobby()
{
	gotoxy(15, 4); printf("��                              �ܡܡܡܡܡ�"); Sleep(430);
	gotoxy(14, 5); printf("��  ��                            ��        ��"); Sleep(430);
	gotoxy(13, 6); printf("��      ��                          ��        ��"); Sleep(430);
	gotoxy(12, 7); printf("��          ��                        ��        ��"); Sleep(430);
	gotoxy(11, 8); printf("��              ��                      ��        ��"); Sleep(430);
	gotoxy(12, 9); printf("��          ��                        �ܡܡܡܡܡ�"); Sleep(430);
	gotoxy(13, 10); printf("��      ��                               ��"); Sleep(430);
	gotoxy(14, 11); printf("��  ��                                 ��"); Sleep(430);
	gotoxy(15, 12); printf("��                                   ��"); Sleep(430);
	gotoxy(15, 13); printf("��                           �ܡܡܡܡܡܡܡܡ�"); Sleep(430);
	gotoxy(15, 14); printf("��"); Sleep(430);
	gotoxy(10, 15); printf("�ܡܡܡܡܡܡܡܡܡܡ�                   �ܡܡܡܡܡܡ�"); Sleep(430);
	gotoxy(36, 16); printf(" ��"); Sleep(430);
	gotoxy(36, 17); printf(" ��"); Sleep(430);
	gotoxy(36, 18); printf(" ��"); Sleep(430);
	gotoxy(36, 19); printf(" ��"); Sleep(430);
	gotoxy(36, 20); printf(" ��"); Sleep(430);
	gotoxy(14, 22); printf("------------------------------------------");
	gotoxy(14, 23); printf("������ �����ϰ� ������ Enter�� �����ּ���.");
	gotoxy(14, 24); printf("------------------------------------------\n\n");
	scanf("%c", &n);
	if (n == '\n');
	introducegmae();
	field();
}

void introducegmae()
{
	gotoxy(17, 60);  printf("�ȳ��ϼ���. ������ӿ� ���Ű� ȯ���մϴ�. "); Sleep(1500);
	gotoxy(8, 61); printf("������ �ټ����� ���� ���� ���� ����, ����, �밢������ �Ϸķ� �̾������� �̱�� �����Դϴ�."); Sleep(1500);
	gotoxy(1, 62); printf("������ ���� ������ ������ 4x3���� ���� �� ������ ��� ���� 6���� �ѹ��� �̾ �¸��ϰ� ��� ���� �ص� ��Ģ�� �ƴմϴ�."); Sleep(1500);
	gotoxy(17, 63); printf("�׷��� ����ְ� ����ּ���. �ٷ� �����մϴ�."); Sleep(1500);
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
					printf("��");
				else if (j == size)
					printf("��");
				else
					printf("��");
			}
			else if (i == size - 1)
			{
				if (j == 0)
					printf("��");
				else if (j == size)
					printf("��");
				else
					printf("��");
			}
			else if (j == size - 1)
			{
				if (i == 0)
					printf("��");
				else if (i == size - 1)
					printf("��");
				else
					printf("��");
			}
			else if (j == size)
			{
				if (i == 0)
					continue;
				else if (i == size - 1)
					printf("��");
				else
					printf("��");
			}
			else
				printf("��");
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
		printblack(); // rock�� 1 �̸� ������ ��
		board[x][y] = black;
	}
	else if (rock == 2)
	{
		printwhite(); // rock�� 2�� ��� ��
		board[x][y] = white;
	}
	else
		return 0;  // rock�� 1�� 2�� �ƴ� �ٸ� ���� �� ��� 0�� ����
	return 1;    // ����� ���� �Է��� �Ȱ�� 1�� ����
}

int main()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  // Ŀ���� �����ִ� �ڵ�

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