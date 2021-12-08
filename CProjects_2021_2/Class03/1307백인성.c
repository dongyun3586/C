#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <stdbool.h> // �Ҹ��� �ڷ��� (��, ������ �Ǵ��ϴ� �ڷ���) ����� ���� �������
#include <windows.h>
#define _CRT_NONSTDC_NO_WARNINGS //conio ���� ����� ���� ������
#define _CRT_SECURE_NO_WARNINGS  //fopen ���� �߻��� �� �ִ� ���� ������
#pragma warning(disable : 4996)  //�굵 ������� ���� �Լ��� �߻��� �� �ִ� ���� ������
#include <conio.h> // getch ������ ���� ���� Ű�� � Ű���� �Ǻ��ϱ� ���� ��� ����
#define Xstart 8   //�⺻ x��ǥ (ó�� �� ���ý�)
#define Ystart 0   //�⺻ y��ǥ (ó�� �� ���ý�)
clock_t Dropstart, Dropend, Reachground; //�ð��� �帧�� ��Ÿ���� ����ü �� �Լ� 
//clock�� �и��� �����̰� ���α׷� ���� �� ���ݱ��� ���� �ð��� �������� return�ϴ� �Լ��̴�
//Dropstart�� ���� �������� ������ �ð��� Dropend�� ���� �������� ���� �ð� ������ ���, Reachground�� ���� �ٴڿ� ���� �� ���� �ð��� �귶����
int x = Xstart;
int y = Ystart;
int k;            //�߰����˽� ����ؼ� ���� �̵���Ű�ų� ȸ����ų�� �ð��� �ʱ�ȭ�Ǽ� �ٴڿ��� ������ ���� ���� �������� �� ������ ���� ���� ����
int harddrop;     //�ϵ����� �����ϱ� ���� ����ϴ� ����
int newblock;     //���� �������� �� �� ���� ���� ���� ����ϴ� ����
int nextblock;    //���� ���� �˸��� ���� ����ϴ� ����
int Rotation = 0; //ȸ���� �Ǻ�
int key;          //����Ű ���� ����
int flag;         //����ؼ� �� ��ü �ʱ�ȭ �� ����� �ϴٺ��� �ʹ� ���ϰ� �����̴� ���� �߰� �� ������ ���̱� ���� �� ���� �������� flag������ ���� �����Ͽ� �� �ʱ�ȭ�� �ּ�ȭ�Ͽ� �������� ����
int END;          //������ ���� ���� �Ǻ� ����
int PAUSE;        //������ �Ͻ����� ����
int score;        //����
int block[7][4][4][4] = { // T��� ��, ���� ��1, ���� ��2, ���ں�, ������ �� 1, ������ �� 2, ���� �� ��
	{ { {0,0,0,0},
		{0,1,0,0},
		{1,1,1,0},
		{0,0,0,0} },
	  { {0,0,0,0},
		{0,1,0,0},
		{0,1,1,0},
		{0,1,0,0} },
	  { {0,0,0,0},
		{0,0,0,0},
		{1,1,1,0},
		{0,1,0,0} },
	  { {0,0,0,0},
		{0,1,0,0},
		{1,1,0,0},
		{0,1,0,0} }
	},
	{ { {0,0,0,0},
		{0,1,1,0},
		{1,1,0,0},
		{0,0,0,0}},
	  { {0,0,0,0},
		{1,0,0,0},
		{1,1,0,0},
		{0,1,0,0}},
	  { {0,0,0,0},
		{0,1,1,0},
		{1,1,0,0},
		{0,0,0,0}},
	  {	{0,0,0,0},
		{1,0,0,0},
		{1,1,0,0},
		{0,1,0,0}}
	},
	{ {	{0,0,0,0},
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0}},
	  { {0,0,0,0},
		{0,1,0,0},
		{1,1,0,0},
		{1,0,0,0}},
	  {	{0,0,0,0},
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0}},
	  {	{0,0,0,0},
		{0,1,0,0},
		{1,1,0,0},
		{1,0,0,0}}
	},
	{ { {0,1,0,0},
		{0,1,0,0},
		{0,1,0,0},
		{0,1,0,0}},
	  {	{0,0,0,0},
		{0,0,0,0},
		{1,1,1,1},
		{0,0,0,0}},
	  {	{0,1,0,0},
		{0,1,0,0},
		{0,1,0,0},
		{0,1,0,0}},
	  {	{0,0,0,0},
		{0,0,0,0},
		{1,1,1,1},
		{0,0,0,0}}
	},
	{ {	{0,0,0,0},
		{1,0,0,0},
		{1,1,1,0},
		{0,0,0,0}},
	  {	{0,0,0,0},
		{1,1,0,0},
		{1,0,0,0},
		{1,0,0,0}},
	  {	{0,0,0,0},
		{1,1,1,0},
		{0,0,1,0},
		{0,0,0,0}},
	  {	{0,1,0,0},
		{0,1,0,0},
		{1,1,0,0},
		{0,0,0,0}}
	},
	{ {	{0,0,0,0},
		{0,0,1,0},
		{1,1,1,0},
		{0,0,0,0}},
	  {	{1,0,0,0},
		{1,0,0,0},
		{1,1,0,0},
		{0,0,0,0}},
	  {	{0,0,0,0},
		{1,1,1,0},
		{1,0,0,0},
		{0,0,0,0}},
	  {	{0,0,0,0},
		{1,1,0,0},
		{0,1,0,0},
		{0,1,0,0}}
	},
	{ {	{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}},
	  {	{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}},
	  {	{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}},
	  {	{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}}
	}
};//�� ��

int map[22][12] = {
	{0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1}
};//�⺻ ��

bool Finishline(int x, int y) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[newblock][Rotation][i][j] == 1) {
				int t = map[i + y][j + x / 2];
				if (t == 1 || t == 2) { // ���� ��, ���� ��
					return true;
				}
			}
		}
	}
	return false;
}  //���� �̵��� �� �ִ��� �Ǵ��ϴ� �Լ�(�̵��� ���� �浹���� �ʴ���)

void hidecursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
} //Ŀ���� ����� �Լ�(�ܺο��� ������)
void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//Ŀ���� ��ǥ�� �̵���Ű���Լ�
void Randomblock() {
	srand(time(NULL));
	nextblock = rand() % 7;
}//���� �����ϰ� �������� �ϴ� �Լ�
void DropBlock() {
	Dropend = clock();
	if (Dropend >= Dropstart + 800 - score / 1000) { //������ �����ϸ� �������� �ӵ��� ����
		if (Finishline(x, y + 1) == true) return;
		else {
			Dropstart = clock();
			Reachground = clock();
			system("cls");
			y++;
			k = 0;
		}
	}
}//�ð��� ������ ���� ���� �����ϵ��� �ϴ� �Լ�
void AttachBlock() {
	if (Finishline(x, y + 1) == true) {
		if (Dropend >= Reachground + 1000 || harddrop == 1 || k >= 15) {
			harddrop = 0;
			k = 0;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (block[newblock][Rotation][i][j] == 1) {
						map[i + y][j + x / 2] = 2;
					}
				}
			}
			x = Xstart;
			y = Ystart;
			flag = true;
			score += 10;
		}
	}
}//���� �ٴڱ��� ������ ���� ���� ���¿��� ���ϰ� ���� ��(��)���� �ٲٱ�
void RemoveLine() {
	for (int i = 21; i >= 2; i--) {
		int Fillblock = 0;
		for (int j = 1; j < 11; j++) {
			if (map[i][j] == 2) {
				Fillblock++;
			}
		}
		if (Fillblock >= 10) {
			score += 100;
			for (int j = 0; i - j >= 0; j++) {
				for (int x = 1; x < 11; x++) {
					if (i - j - 1 >= 0)
						map[i - j][x] = map[i - j - 1][x];
					else
						map[i - j][x] = 0;
				}
			}
			system("cls");
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 11; j++) {
			if (map[i][j] == 2 || map[i][j] == 1) END = 1;
		}
	}
}//������ ��ä��� ���� ����� �߰� ������ �ִ� �Լ�
void DrawMap() {
	gotoxy(0, 4);
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 12; j++) {
			if (map[i][j] == 1) {
				gotoxy(j * 2, i);
				printf("��");
			}
			else if (map[i][j] == 2) {
				gotoxy(j * 2, i);
				printf("��");
			}
		}
	}
}//���� ���� ����ϴ� �Լ�
void HardDrop() {
	int i = 0, a = 1;
	while (!i) {
		if (Finishline(x, y + a) == true) {
			i = 1;
			y += a - 1;
			system("cls");
			harddrop = 1;
		}
		else a++;
	}
}//�ϵ����� �ϵ��� �ϴ� �Լ�
void DrawBlock() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[newblock][Rotation][i][j] == 1) {
				gotoxy(x + j * 2, y + i);
				printf("��");
			}
		}
	}
}//���� �������� ���� ����ϴ� �Լ�
void Gameover() {
	system("cls");
	FILE* fp;
	fp = fopen("highscore.txt", "r");
	if (!fp) {
		printf("Fail to open the file as the write mode.\n");
		return 0;
	}
	int highscore;
	char highname[20];
	fscanf(fp, "%s %d", highname, &highscore);
	system("cls");
	gotoxy(8, 8);
	printf("��Ʈ������ �÷��� ���ּż� �����մϴ�.");
	gotoxy(8, 9);
	printf("����� ������ %d���Դϴ�.", score);
	if (highscore >= score) {
		gotoxy(8, 10);
		printf("�ƽ��׿�, �ְ������� %s�� %d ���Դϴ�.\n", highname, highscore);
		gotoxy(8, 11);
		printf("�� �� ����غ�����.");
	}
	else if (highscore < score) {
		fclose(fp);
		gotoxy(8, 10);
		printf("�����մϴ�. �ű���̿���!\n");
		gotoxy(8, 11);
		printf("�̴ϼ��� �Է����ּ��� : ");
		char initial[20];
		scanf("%s", initial);
		fp = fopen("highscore.txt", "w");
		if (!fp) {
			printf("Fail to open the file as the write mode.\n");
			return 0;
		}
		fprintf(fp, "%s %d", initial, score);
	}
	printf("TETRIS�� �����մϴ�.");
	fclose(fp);
}//������ �������� �ν��ϰ� "hidhscore.txt" ���Ͽ� ����� �ְ��ϰ� ���Ͽ� �ְ����Ͻ� �̴ϼ��� ���⵵�� �ϴ� �Լ�

void Inputkey()
{
	if (_kbhit()) {
		key = _getch();
		switch (key) {
		case 72: // up
			Rotation++;
			if (Finishline(x, y) == false) {
				if (Rotation >= 4) Rotation = 0;
				Reachground = clock();
				system("cls");
			}
			else Rotation -= 1;
			break;
		case 75: // left
			if (Finishline(x - 2, y) == false) {
				x -= 2;
				Reachground = clock();
				system("cls");
				k++;
			}
			break;
		case 77: // right
			if (Finishline(x + 2, y) == false) {
				x += 2;
				Reachground = clock();
				system("cls");
				k++;
			}
			break;
		case 27:
			PAUSE = 1;
			break;
		case 80: // down
			if (Finishline(x, y + 1) == false) {
				system("cls");
				y++;
			}
			break;
		case 32://harddrop
			HardDrop();
			break;
		}
	}

} // Ű�� ������ ���� Ű�� �ν��ϰ� �˸��� �ൿ�� �ϵ��� �ϴ� �Լ�
int remote() {
	if (kbhit()) return getch();
	else return -1;
}//�ܺο��� ������ �Լ� (����Ű ���� �Է� �� ����)

void gamestart() {
	gotoxy(7, 1);
	printf("3 seconds left..");
	Sleep(200);
	gotoxy(7, 1);
	printf("3 seconds left...");
	Sleep(200);
	gotoxy(7, 1);
	printf("3 seconds left....");
	Sleep(200);
	gotoxy(7, 1);
	printf("3 seconds left..");
	Sleep(200);
	gotoxy(7, 1);
	printf("3 seconds left...");
	Sleep(200);
	gotoxy(7, 1);
	printf("3 seconds left....");
	gotoxy(7, 1);
	printf("2 seconds left..");
	Sleep(200);
	gotoxy(7, 1);
	printf("2 seconds left...");
	Sleep(200);
	gotoxy(7, 1);
	printf("2 seconds left....");
	Sleep(200);
	gotoxy(7, 1);
	printf("2 seconds left..");
	Sleep(200);
	gotoxy(7, 1);
	printf("2 seconds left...");
	Sleep(200);
	gotoxy(7, 1);
	printf("2 seconds left....");
	gotoxy(7, 1);
	printf("1 seconds left..");
	Sleep(200);
	gotoxy(7, 1);
	printf("1 seconds left...");
	Sleep(200);
	gotoxy(7, 1);
	printf("1 seconds left....");
	Sleep(200);
	gotoxy(7, 1);
	printf("1 seconds left..");
	Sleep(200);
	gotoxy(7, 1);
	printf("1 seconds left...");
	Sleep(200);
	gotoxy(7, 1);
	printf("1 seconds left....");
	gotoxy(7, 1);
	printf("                         ");
	gotoxy(7, 1);
	printf("Game Start!!");
	Sleep(200);
	system("cls");
}//ó�� ���� ���۽� ���θ޴����� �Ѿ�� ����

void next1() {
	int k = nextblock;
	if (k == 0) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //���ڻ� ���� �Լ�
		gotoxy(30, 6);
		printf("��");
		gotoxy(32, 6);
		printf("��");
		gotoxy(34, 6);
		printf("��");
		gotoxy(32, 5);
		printf("��");
	}
	else if (k == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		gotoxy(34, 5);
		printf("��");
		gotoxy(32, 5);
		printf("��");
		gotoxy(30, 6);
		printf("��");
		gotoxy(32, 6);
		printf("��");
	}
	else if (k == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		gotoxy(30, 5);
		printf("��");
		gotoxy(32, 5);
		printf("��");
		gotoxy(32, 6);
		printf("��");
		gotoxy(34, 6);
		printf("��");
	}
	else if (k == 3) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		gotoxy(30, 4);
		printf("��");
		gotoxy(30, 5);
		printf("��");
		gotoxy(30, 6);
		printf("��");
		gotoxy(30, 7);
		printf("��");
	}
	else if (k == 4) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		gotoxy(30, 5);
		printf("��");
		gotoxy(30, 6);
		printf("��");
		gotoxy(32, 6);
		printf("��");
		gotoxy(34, 6);
		printf("��");
	}
	else if (k == 5) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		gotoxy(30, 6);
		printf("��");
		gotoxy(32, 6);
		printf("��");
		gotoxy(34, 5);
		printf("��");
		gotoxy(34, 6);
		printf("��");
	}
	else if (k == 6) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		gotoxy(30, 5);
		printf("��");
		gotoxy(30, 6);
		printf("��");
		gotoxy(32, 5);
		printf("��");
		gotoxy(32, 6);
		printf("��");
	}
}//������ �� �� ���
void next() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	gotoxy(26, 1);
	printf("score : %d", score);
	gotoxy(26, 2);
	printf("    NEXT    ");
	gotoxy(26, 3);
	printf("�������");
	gotoxy(26, 4);
	printf("��        ��");
	gotoxy(26, 5);
	printf("��        ��");
	gotoxy(26, 6);
	printf("��        ��");
	gotoxy(26, 7);
	printf("��        ��");
	gotoxy(26, 8);
	printf("�������");
	next1();
}//NEXT �κ� ���
void menu() {
	gotoxy(1, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("       ������ ����� ������  �����  �����   ����\n");
	gotoxy(1, 3);
	printf("           ��     ��           ��      ��    ��     ��     �� \n");
	gotoxy(1, 4);
	printf("           ��     �����     ��      ����       ��      ����\n");
	gotoxy(1, 5);
	printf("           ��     ��           ��      ��   ��      ��           ��\n");
	gotoxy(1, 6);
	printf("           ��     �����     ��      ��    ��  �����   ���� \n");
	gotoxy(1, 9);
	printf("Right : ��");
	gotoxy(1, 10);
	printf("Left  : ��");
	gotoxy(1, 11);
	printf("Down  : ��");
	gotoxy(1, 12);
	printf("Rotate: ��");
	gotoxy(1, 13);
	printf("HardDrop: Space");
	gotoxy(1, 14);
	printf("Pause : Esc");
	gotoxy(17, 10);
	printf("TETRIS�� 1307 �����Ϳ� ���� ����������ϴ�.");
	gotoxy(17, 11);
	printf("���� �������� �÷����ϰ� ��� TETRIS�� ���۱��� 1307 �����Ϳ��� �ֽ��ϴ�.");
	gotoxy(17, 12);
	printf("�׷� ��� ��ſ� TETRIS �ϼ���.");
	while (1) {
		int key = remote();
		if (key == 's' || key == 'S') break;
		gotoxy(15, 14);
		printf("-----Press S to start-----");
		Sleep(300);
		gotoxy(15, 14);
		printf("                           ");
		Sleep(300);
	}
	system("cls");
	gamestart();
}//����Ű ���� �� ���ӽ��� �� ����ϴ� �޴�ȭ��

int main() {
	score = 0;
	END = 0;
	PAUSE = 0;
	menu();
	hidecursor();
	Dropstart = clock();
	Randomblock();
	while (1) {
		newblock = nextblock;
		Randomblock();
		flag = false;
		while (flag == false && END == 0) {
			DrawMap();
			if (PAUSE == 1) {
				gotoxy(30, 10);
				printf("�簳�Ϸ��� EnterŰ�� �����ּ���");
				char u;
				scanf("%c", &u);
				rewind(stdin);//��������
				PAUSE = 0;
			}
			next();
			Inputkey();
			DrawBlock();
			DropBlock();
			AttachBlock();
			RemoveLine();
		}
		if (END == 1) break;
	}
	Gameover();
	return 0;
}//���� �Լ�