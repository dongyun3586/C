#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//���� ���
void Print(int n)
{
	switch (n)
	{
	case 0:
		printf("  ");
		break;
	case 1:
		printf("��");
		break;
	case 2:
		printf("��");
		break;
	case 3:
		printf("��");
		break;
	case 4:
		printf("��");
		break;
	case 5:
		printf("��");
		break;
	case 6:
		printf("��");
		break;
	case 7:
		printf("��");
		break;
	case 8:
		printf("��");
		break;
	case 9:
		printf("��");
		break;
	}
}

//�ܼ�â�� ��ǥ�� �������ֱ�
void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//���� ù ����
void Board(int n, int m)	//���� m, ���� n
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
			printf("��");
		printf("\n");
	}
}

//����ȭ��
void Main()
{
	//printf("���������������������������������������������������\n");
	//printf("���������������������������������������������������\n");
	//printf("���������������������������������������������������\n");
	//printf("���������������������������������������������������\n");
	//printf("���������������������������������������������������\n");
	//printf("���������������������������������������������������\n");
	//printf("���������������������������������������������������\n");
	//printf("���������������������������������������������������\n");
	//printf("���������������������������������������������������\n");
	//printf("���������������������������������������������������\n");

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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);	//���������� �Ⱥ��̰� ���
				printf("��");
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);	//������� ���̰� ���
				printf("��");
			}
		}
		printf("\n");
	}
}

//����ȭ�� �� ����â
int Menu()
{
	int key;
	int x = 55, y = 20;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(x - 2, y);
	printf("> ���� ����");
	gotoxy(x, y + 1);
	printf("���� ����");
	gotoxy(x + 2, y + 2);
	printf("����");

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

//���� ����â
int Level()
{
	int key = 0;
	int x = 10, y = 10;
	gotoxy(x - 2, y);
	printf("> �ʱ�");
	gotoxy(x, y + 1);
	printf("�߱�");
	gotoxy(x, y + 2);
	printf("���");

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

int c[16][30] = { 0 };	//0�϶��� ������ ���� ��, 1�϶��� ���� ��, 2�϶��� ����� ������

void Check(int x, int y, int n, int m, int k, int mine[][30])	//���� n, ���� m
{
	if (k == 5)
		return 0;
	if (mine[y][x] != 9 && c[y][x] == 0)	//��ź �ƴ� ��, Ȯ�� �� �Ѱ�
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
	else if (mine[y][x] == 9 && k == 0)	//��ź ��ġ�� �� ������ �� ��, ó�� ������ ��
	{
		system("cls");
		gotoxy(0, 0);
		printf("���ڸ� �����߽��ϴ�!\n");
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


void Game(int n, int m, int mi) //���� n ���� m
{
	int mine[16][30];
	int d = mi;	//���� ���� ���� ǥ���ϱ�
	int x = 0, y = 0, f = 0;	//x,y�� ��ǥ, f�� 0�϶� ����, 1�϶� ��� �ȱ�, 2�϶� ��� ����
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
				if ((i - 1) >= 0)	//���� ��ġ���� �� �� 3�� �������� �Ǵ�
				{
					if ((j - 1) >= 0 && mine[i - 1][j - 1] == 9) count++;
					if (mine[i - 1][j] == 9) count++;
					if ((j + 1) < n && mine[i - 1][j + 1] == 9) count++;
				}

				if ((j - 1) >= 0 && mine[i][j - 1] == 9) count++;
				if ((j + 1) < n && mine[i][j + 1] == 9) count++;

				if ((i + 1) < m)	//���� ��ġ���� �Ʒ� �� 3�� �������� �Ǵ�
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

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	//������� ���

	gotoxy(2 * n + 3, 5);
	printf("���� ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("��");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("�� ����");
	gotoxy(2 * n + 5, 6);
	printf("%4d", d);

	while (1)
	{
		int k = 0;
		gotoxy(0, m + 2);
		printf("��ǥ�� �Է��ϼ���\n");
		gotoxy(0, m + 4);
		printf("���ڸ� �Է��ϼ���\n����:0    ��� �ȱ�:1    ��� ����:2\n");
		gotoxy(0, m + 3);
		scanf("%d %d", &x, &y);
		if (x > n || y > m || x < 1 || y < 1)
		{
			gotoxy(0, m + 3);
			printf("���� �̳��� ���� �Է����ּ���");
			Sleep(1000);
			gotoxy(0, m + 3);
			printf("                                                        ");
			continue;
		}
		gotoxy(0, m + 6);
		scanf("%d", &f);
		switch (f)
		{
		case 0:	//����
			Check(x - 1, y - 1, n, m, k, mine);
			break;
		case 1:	//��� �ȱ�
			if (c[y - 1][x - 1] == 0)	//Ȯ�ε��� ���� ��
			{
				gotoxy(2 * x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("��");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				c[y - 1][x - 1] = 2;
				d--;	//��� ���� ����
				gotoxy(2 * n + 5, 6);
				printf("%4d", d);
			}
			else
			{
				gotoxy(0, m + 6);
				printf("�̹� �����ų� ����� �Ⱦ��� �ֽ��ϴ�. �ٽ� �Է����ּ���");
				Sleep(1000);
				gotoxy(0, m + 6);
				printf("                                                        ");
				gotoxy(0, m + 6);
			}
			break;
		case 2:	//��� ����
			if (c[y - 1][x - 1] == 2)	//����� �Ⱦ��� ���϶�
			{
				gotoxy(2 * x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("��");
				c[y - 1][x - 1] = 0;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				d++;	//��� ���� �߰�
				gotoxy(2 * n + 5, 6);
				printf("%4d", d);

			}
			else
			{
				gotoxy(0, m + 6);
				printf("����� �����ϴ�. �ٽ� �Է����ּ���");
				Sleep(1000);
				gotoxy(0, m + 6);
				printf("                                                        ");
			}
		default:	//f�� ���� 0,1,2 �̿��� �� �϶� �ٽ� �Է¹ޱ�
		{
			gotoxy(0, m + 6);
			printf("�������� ���� ���Դϴ�. �ٽ� �Է����ּ���");
			Sleep(1000);
			gotoxy(0, m + 6);
			printf("                                                        ");
		}
		break;
		}
		int finish = 0;	//finish �� 0�̾�� ������ ����->n*m �迭 c�� ���� 0�� ����� ��.
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
			printf("���ϵ帳�ϴ�. ������ Ŭ���� �ϼ̽��ϴ�!");
			return 0;
		}
		gotoxy(0, m + 3);
		printf("         ");
		gotoxy(0, m + 6);
		printf("         ");
	}

}

int main() {
	system("mode con cols=120 lines=30"); //�ܼ�â�� ũ�� ����
choose:
	system("cls");
	Main();
	int menu = Menu();
	int mine[16][30] = { 0 };
	int key = 0;
	system("cls");
	if (menu == 0)	//���� ����
	{
		int level = Level();
		system("cls");
		if (level == 0)	//�ʱ� 9*9, ���� 10��
		{
			Game(9, 9, 10);
		}
		else if (level == 1)	//�߱� 16*16 ���� 40��
		{
			Game(16, 16, 40);
		}
		else if (level == 2)	//��� 16*30 ���� 99��
		{
			Game(30, 16, 99);
		}
	}
	else if (menu == 1)	//���� ����
	{
		system("cls");
		printf("���̵��� �ʱ�, �߱�, ����� �ִ�\n");
		printf("\n");
		printf("-�ʱ� 9 * 9, ���� 10��\n");
		printf("-�߱� 16 * 16 ���� 40��\n");
		printf("-��� 30 * 16 ���� 99��\n\n\n");
		printf("1.�Է��� ��ǥ�� ������ ������ ������ ������ �Է��Ѵ�.\n");
		printf("2.ĭ�� ���⸦ ���Ѵٸ� 0, ����� �Ȱ� �ʹٸ� 1, ����� ���� ������ 2�� �Է��Ѵ�.\n");
		printf("3.���� ���ڰ� �ִ� ĭ�� ���� �Ǹ� ������ �ڵ����� ���̳���.\n");
		printf("4.���ڸ� ������ ��� ĭ�� ���� ������ �κп� ��� ����� �Ⱦ��� �� �̰�ٰ� ������ �ȴ�.\n\n\n");
		printf("�ǵ��� ������ ����Ű�� �����ּ���.");

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
	else	//���� ����
	{
		return 0;
	}
}