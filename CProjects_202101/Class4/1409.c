#include<stdio.h>
#include<Windows.h>

//�ܼ�â�� ��ǥ�� �������ֱ�
void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//�º��� ���� �Ǵ�
int Check(char a[20][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			//����
			if (a[i][j] == 'b' && a[i + 1][j] == 'b' && a[i + 2][j] == 'b' && a[i + 3][j] == 'b' && a[i + 4][j] == 'b')
			{
				system("cls");
				gotoxy(21, 21);
				printf("������ �� ���!\n");
				return 0;
			}
			if (a[i][j] == 'w' && a[i + 1][j] == 'w' && a[i + 2][j] == 'w' && a[i + 3][j] == 'w' && a[i + 4][j] == 'w')
			{
				system("cls");
				gotoxy(21, 21);
				printf("��� �� ���!\n");
				return 0;
			}
			//����
			if (a[i][j] == 'b' && a[i][j + 1] == 'b' && a[i][j + 2] == 'b' && a[i][j + 3] == 'b' && a[i][j + 4] == 'b')
			{
				system("cls");
				gotoxy(21, 21);
				printf("������ �� ���!\n");
				return 0;
			}
			if (a[i][j] == 'w' && a[i][j + 1] == 'w' && a[i][j + 2] == 'w' && a[i][j + 3] == 'w' && a[i][j + 4] == 'w')
			{
				system("cls");
				gotoxy(21, 21);
				printf("��� �� ���!\n");
				return 0;
			}
			//�밢��(��)
			if (a[i][j] == 'b' && a[i + 1][j + 1] == 'b' && a[i + 2][j + 2] == 'b' && a[i + 3][j + 3] == 'b' && a[i + 4][j + 4] == 'b')
			{
				system("cls");
				gotoxy(21, 21);
				printf("������ �� ���!\n");
				return 0;
			}
			if (a[i][j] == 'w' && a[i + 1][j + 1] == 'w' && a[i + 2][j + 2] == 'w' && a[i + 3][j + 3] == 'w' && a[i + 4][j + 4] == 'w')
			{
				system("cls");
				gotoxy(21, 21);
				printf("��� �� ���!\n");
				return 0;
			}
			///�밢��(��)
			if (a[i][j] == 'b' && a[i - 1][j + 1] == 'b' && a[i - 2][j + 2] == 'b' && a[i - 3][j + 3] == 'b' && a[i - 4][j + 4] == 'b')
			{
				system("cls");
				gotoxy(21, 21);
				printf("������ �� ���!\n");
				return 0;
			}
			if (a[i][j] == 'w' && a[i - 1][j + 1] == 'w' && a[i - 2][j + 2] == 'w' && a[i - 3][j + 3] == 'w' && a[i - 4][j + 4] == 'w')
			{
				system("cls");
				gotoxy(21, 21);
				printf("��� �� ���!\n");
				return 0;
			}
		}
	}
}

//���� ù ����
void Board()
{
	gotoxy(0, 0);
	for (int i = 0; i < 20; i++)
	{
		for (int k = 0; k < 20; k++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			printf("��");
		}
		printf("\n");
	}
	gotoxy(50, 10);
	printf("(0,0)~(19,19)������ ��ǥ�� �Է��ϼ���.");
}

//��� �� ���ϴ� ��ǥ�� ���
void White(int x, int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy((2 * x), y);
	printf("��");
}

//������ �� ���ϴ� ��ǥ�� ���
void Black(int x, int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy((2 * x), y);
	printf("��");
}

int main()
{
	int n = 0, x, y; //� ���� �������� �Ǵ��� �� ���, ��ǥ �Է¹��� ���� 2��
	char a[20][20] = { 0 }; //�º��� ���� �Ǵ��� �� ���

	system("mode con cols=100 lines=22"); //�ܼ�â�� ũ�� ����

	//3���Ŀ� ����!
	for (int i = 3; i > 0; i--)
	{
		gotoxy(20, 10);
		printf("Start in %d", i);
		Sleep(1000); //1�ʰ� ���
		system("cls"); //�ܼ�â ���� �����
	}

	//�ٵ��� ����
	Board();

	//�ٵϵ� ����
	while (1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //�ܼ�â���� �۾� ���� ������� ����
		gotoxy(50, 13);
		printf("          ");
		gotoxy(50, 12);
		if (n % 2 == 1)
			printf(">>>>>>>�� �� ���� �����Դϴ�<<<<<<<");
		else
			printf(">>>>>>���� �� ���� �����Դϴ�<<<<<<");
		gotoxy(50, 13);
		scanf("%d %d", &x, &y);
		while (a[x][y] != 0) //�̹� �ٵϵ��� ���� ���� �ٽ� �������� �� �� �ٽ� �Է��϶�� �˷��ֱ�
		{
			gotoxy(50, 12);
			if (n % 2 == 1)
				printf(">>>>>>>�� �� �� �ٽ� �ϼ���<<<<<<<");
			if (n % 2 == 0)
				printf(">>>>>>>���� �� �� �ٽ� �ϼ���<<<<<");
			gotoxy(50, 13);
			printf("       ");
			gotoxy(50, 13);
			scanf("%d %d", &x, &y);
		}

		//�ٵϵ��� �ƹ��͵� ���� ���� ���� ���
		if (n % 2 == 1)
		{
			White(x, y); //�� �ٵϵ� ����
			a[x][y] = 'w';
			if (Check(a) == 0) //�º� ����
				break;
		}
		if (n % 2 == 0)
		{
			Black(x, y); //���� �ٵϵ� ����
			a[x][y] = 'b';
			if (Check(a) == 0) // �º� ����
				break;
		}
		n++;
	}
}