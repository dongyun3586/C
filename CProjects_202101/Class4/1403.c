#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define X 3
#define Y 2

int x[200], y[200];
int appleX, appleY;//���� ��ǥ
int score;
int speed = 100;
int length;
int way;
int key;
int hard;
int bestscore = 0;
int lastscore = 0;
int width;
int height;

int mode();
void title(int hard);
void title2();
void reset();
void map();
void move(int way);
void pause();
void gameover();
void apple();
void gotoxy();
void DoSome();
void DoProgress();

int main() {
	hard = mode();//���̵� �ޱ�
	title(hard);

	while (1) {
		key = getch();//Ű���� �޴´�.
		Sleep(speed);//�ӵ���ŭ ����� �����ϱ�

		switch (key) {
		case 'w':
		case 'a':
		case 's':
		case 'd':
			if ((way == 'w' && key != 's') || (way == 'd' && key != 'a') || (way == 'a' && key != 'd') || (way == 's' && key != 'w')) {
				way = key;//������ �ݴ� ���� ���� �� ����
			}
			key = 0;
			break;
		case 'p'://���� ����
			pause();
			break;
		case 'x':
			exit(0);//���α׷� ����
		}
		move(way);
	}
}
void move(int way) {
	int i;
	if (x[0] == appleX && y[0] == appleY) {//��� �Ծ��� ��
		score += 100;
		apple();
		length++;
	}
	if (x[0] == 0 || x[0] == width - 1 || y[0] == 0 || y[0] == height - 1) {
		gameover();// ���� �ھ��� ��
		return;

	}
	for (i = 1; i < length; i++) {
		if (x[0] == x[i] && y[0] == y[i]) {//�ڱ� ���뿡 �Ӹ��ھ��� ��
			gameover();
			return;
		}
	}

	gotoxy(X + x[length - 1], Y + y[length - 1], "  ");//���� �� ��ǥ�� ���ش�.
	for (i = length - 1; i > 0; i--) {//���� ������ �� ��ǥ �������� �ű��.
		x[i] = x[i - 1];
		y[i] = y[i - 1];
	}
	gotoxy(X + x[0], Y + y[0], "��");//���� ����
	if (way == 'a') --x[0];
	if (way == 'd') ++x[0];
	if (way == 'w') --y[0];
	if (way == 's') ++y[0];
	gotoxy(X + x[i], Y + y[i], "��");//���� �Ӹ�
}

void title(int hard) {
	switch (hard) {
	case 1://���� ����
		width = 40;
		height = 30;
		title2();
		break;
	case 2://����
		width = 32;
		height = 24;
		title2();
		break;
	case 3://�����
		width = 32;
		height = 24;
		speed -= 5;
		title2();
		break;
	case 4://�ؾ�
		width = 24;
		height = 18;
		speed -= 7;
		title2();
		break;
	}
}
void title2() {
	DoSome();//�ε�â ���
	system("cls");//�ε�â ����
	printf("LOADING COMPLETE!!");
	Sleep(300);//��� ����
	system("cls");
	map();//�� �׸���
	for (int i = Y + 1; i < Y + height - 1; i++) {
		for (int j = X + 1; j < X + width - 1; j++) gotoxy(j, i, "  ");
	}
	gotoxy(X + (width / 2) - 7, Y + 5, "+--------------------------+");
	gotoxy(X + (width / 2) - 7, Y + 6, "|        S N A K E         |");
	gotoxy(X + (width / 2) - 7, Y + 7, "+--------------------------+");

	gotoxy(X + (width / 2) - 7, Y + 9, "  - �ƹ� Ű�� ���� ���� - ");

	gotoxy(X + (width / 2) - 7, Y + 11, "   - w,a,s,d : Move    ");
	gotoxy(X + (width / 2) - 7, Y + 12, "   - p : Pause             ");
	gotoxy(X + (width / 2) - 7, Y + 13, "   - x : Quit              ");//����ȭ��
	while (1) {
		if (kbhit()) {
			key = getch();
			if (key == 'x')
				exit(0);
			else
				break;
		}
		gotoxy(X + (width / 2) - 7, Y + 9, " - �ƹ� Ű�� ���� ���� - ");
		Sleep(300);
		gotoxy(X + (width / 2) - 7, Y + 9, "                            ");
		Sleep(300);

	}
	reset();
}
void reset() {
	int i;
	system("cls");
	map();

	way = 'a';    //�������� ����
	length = 5;
	score = 0;
	for (i = 0; i < length; i++) {
		x[i] = width / 2 + i;
		y[i] = height / 2;
		gotoxy(X + x[i], Y + y[i], "��");
	}
	gotoxy(X + x[0], Y + y[0], "��");
	apple();
}
int mode() {
	int ans;
A:
	printf("� ��忡�� �Ͻðڽ��ϱ�?\n");
	printf("1. ����\n");
	printf("2. ����\n");
	printf("3. �����\n");
	printf("4. �̰� ����� �� �����̳�?\n");
	scanf("%d", &ans);
	if (ans != 1 && ans != 2 && ans != 3 && ans != 4) {
		system("cls");
		printf("�ٽ� �������ֽʽÿ�\n");
		goto A;
	}
	system("cls");
	return ans;
}
void map() {//������ width�� height���� ��� ���� ������ ��� �׸�� ä��
	for (int i = 0; i < width; i++) {
		gotoxy(X + i, Y, "��");
	}
	for (int i = Y + 1; i < Y + height - 1; i++) {
		gotoxy(X, i, "��");
		gotoxy(X + width - 1, i, "��");
	}
	for (int i = 0; i < width; i++) {
		gotoxy(X + i, Y + height - 1, "��");
	}
}
void gotoxy(int x, int y, char* s) {//���ͳݿ��� ������ ��
	COORD pos = { 2 * x,y };//���ӿ��� �� ĭ�� 2����Ʈ �̹Ƿ� *2����
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s", s);
}
void apple() {
	int crush = 0;
	gotoxy(X, Y + height, " YOUR SCORE: ");
	printf("%4d, LAST SCORE: %4d, BEST SCORE: %4d", score, lastscore, bestscore);
	srand(time(NULL));
	while (1) {

		appleX = (rand() % (width - 2)) + 1;
		appleY = (rand() % (height - 2)) + 1;

		for (int i = 0; i < length; i++) {
			if (appleX == x[i] && appleY == y[i]) {
				crush = 1;//����� ������ ������ ��
				break;
			}
		}

		if (crush == 1)
			continue;

		gotoxy(X + appleX, Y + appleY, "*");//�浹 �� �����
		speed -= 3;
		break;

	}
}

void gameover() {
	system("cls");
	map();
	gotoxy(X + (width / 2) - 6, Y + 5, "+----------------------+");
	gotoxy(X + (width / 2) - 6, Y + 6, "|       GAME OVER      |");
	gotoxy(X + (width / 2) - 6, Y + 7, "+----------------------+");
	gotoxy(X + (width / 2) - 6, Y + 8, "      Score:");
	printf("%d", score);

	if (score >= bestscore) {
		bestscore = score;

		gotoxy(X + (width / 2) - 4, Y + 10, " WOW! BEST SCORE! ");
	}
	gotoxy(X + (width / 2) - 7, Y + 12, "PRESS ANY KEYS TO RESTART");
	Sleep(500);
	while (kbhit())
		getch();
	key = getch();
	system("cls");
	title2();
}

void pause() {//����
	while (1) {
		if (key == 'p') {
			gotoxy(X + (width / 2) - 9, Y, "< PAUSE : PRESS ANY KEY TO RESUME > ");
			Sleep(400);
			gotoxy(X + (width / 2) - 9, Y, "                                    ");
			Sleep(400);//��������
		}
		else {
			map();
			return;
		}
		if (kbhit())
			key = getch();

	}
}
void DoSome()//�ε�â
{
	int total = 1000;
	int step = 0;

	while (step < total)
	{
		//do some action
		Sleep(0.3);

		step += 1;

		DoProgress("Download: ", step, total);
	}

	printf("\n");

}//���ͳݿ��� ������, ��ó: https://twinw.tistory.com/200 [����ǲ�]

void DoProgress(char label[], int step, int total)//�ε�
{
	//progress width
	const int pwidth = 72;

	//minus label len
	int width = pwidth - strlen(label);
	int pos = (step * width) / total;


	int percent = (step * 100) / total;

	//set green text color, only on Windows
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	printf("%s[", label);

	//fill progress bar with =
	for (int i = 0; i < pos; i++)  printf("%c", '=');//=�� ä�� �ε���ó�� ����

	//fill progress bar with spaces
	printf("% *c", width - pos + 1, ']');
	printf(" %3d%%\r", percent);

	//reset text color, only on Windows
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08);
}


