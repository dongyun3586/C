#ifndef __STDIO_H__
#define __STDIO_H__

#include <stdio.h>

#endif

#ifndef __WINDOWS_H__
#define __WINDOWS_H__

#include <windows.h>

#endif

#ifndef __STDLIB_H__
#define __STDLIB_H__

#include <stdlib.h>

#endif

#ifndef __CONIO_H__
#define __CONIO_H__

#include <conio.h>

#endif

#ifndef __TIME_H__
#define __TIME_H__

#include <time.h>

#endif

#ifndef __STRING_H__
#define __STRING_H__

#include <string.h>

#endif

#ifndef __MATH_H__
#define __MATH_H__

#include <math.h>

#endif

typedef struct {
	int loc;// ������ �ǿ��� ��ǥ
	int over; // ������ �� �� �� ���� 0, �� ���� 1�� ��
}mal;

typedef struct {
	mal mal[5];

}team;

char p1[10], p2[10];
void map();
void start();
int yutrolling();
void settings();
void explainrule();
void pan();
void resetmessage();
void reset(team* a1, team* a2);
void hidecursor();
int game(team* p1, team* p2, int turn, int overcount1, int overcount2);


#define do 1
#define gae 2
#define gul 3
#define yut 4  
#define mo 0
#define _CRT_SECURE_NO_WARNINGS

int beforekan1[5] = { 0 }, beforekan2[5] = { 0 };

int getKeyDown() {
	if (kbhit())
		return getch();
	else return -1;
}
void gotoxy(int x, int y, char* s) {
	COORD pos = { 2 * x,y };//��ȣ���� �ܼ��� �� ĭ�� �����ϱ� ������ 2*�� ���ش�.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s", s);
}

void endmessage(char winner) {
	system("cls");
	gotoxy(30, 30, "�����մϴ�! %s���� �¸��Դϴ�!", winner);
}

void printmal(team* p1, team* p2) {//�� �Լ��� ������� ���� �������� ���� ���� �밡���̴�
	if (p1->mal[1].loc == 1) {// �� �Լ��� ����鼭 ��û�� ��Ÿ�� �Դ�
		gotoxy(53, 54, "1");
	}
	if (p1->mal[1].loc == 2) {
		gotoxy(53, 44, "1");
	}
	if (p1->mal[1].loc == 3) {
		gotoxy(53, 35, "1");
	}
	if (p1->mal[1].loc == 4) {
		gotoxy(53, 26, "1");
	}
	if (p1->mal[1].loc == 5) {
		gotoxy(53, 17, "1");
	}
	if (p1->mal[1].loc == 6) {
		gotoxy(53, 9, "1");
	}
	if (p1->mal[1].loc == 7) {
		gotoxy(45, 8, "1");
	}
	if (p1->mal[1].loc == 8) {
		gotoxy(36, 8, "1");
	}
	if (p1->mal[1].loc == 9) {
		gotoxy(27, 8, "1");
	}
	if (p1->mal[1].loc == 10) {
		gotoxy(18, 8, "1");
	}
	if (p1->mal[1].loc == 11) {
		gotoxy(8, 9, "1");
	}
	if (p1->mal[1].loc == 12) {
		gotoxy(9, 17, "1");
	}
	if (p1->mal[1].loc == 13) {
		gotoxy(9, 26, "1");
	}
	if (p1->mal[1].loc == 14) {
		gotoxy(9, 35, "1");
	}
	if (p1->mal[1].loc == 15) {
		gotoxy(9, 44, "1");
	}
	if (p1->mal[1].loc == 16) {
		gotoxy(8, 54, "1");
	}
	if (p1->mal[1].loc == 17) {
		gotoxy(53, 54, "1");
	}
	if (p1->mal[1].loc == 18) {
		gotoxy(53, 54, "1");
	}
	if (p1->mal[1].loc == 19) {
		gotoxy(53, 54, "1");
	}
	if (p1->mal[1].loc == 20) {
		gotoxy(53, 54, "1");
	}
	if (p1->mal[1].loc == 21) {
		gotoxy(53, 54, "1");
	}
	if (p1->mal[1].loc == 22) {
		gotoxy(53, 54, "1");
	}
	if (p1->mal[1].loc == 23) {
		gotoxy(53, 54, "1");
	}
	if (p1->mal[1].loc == 24) {
		gotoxy(53, 54, "1");
	}
	if (p1->mal[1].loc == 25) {
		gotoxy(53, 54, "1");
	}
	if (p1->mal[1].loc == 26) {
		gotoxy(53, 54, "1");
	}
	if (p1->mal[1].loc == 27) {
		gotoxy(53, 54, "1");
	}
	if (p1->mal[1].loc == 28) {
		gotoxy(53, 54, "1");
	}
	if (p1->mal[1].loc == 29) {
		gotoxy(53, 54, "1");
	}

}



int main() {
	int turn = 1;
	hidecursor();
	team p1, p2;
	int key = 0, ans, move, overcount1 = 0, overcount2 = 0;
	system("title ������");
	//system("mode con:cols=200 lines=170");
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	start();
	map();
	reset(&p1, &p2);
	pan();
	while (1) {

		key = getKeyDown();
		if (key == 's' || key == 'S') settings();
		if (key == 'x' || key == 'X') {
		A:
			gotoxy(5, 61, "������ �����ðڽ��ϱ�? (�� : 1, �ƴϿ�:2)");
			scanf("%d", &ans);
			if (ans == 2) gotoxy(5, 61, "                                                 ");
			else if (ans == 1) exit(0);
			else {
				gotoxy(5, 60, "�ٽ� �Է����ֽʽÿ�");
				system("sleep 500");
				goto A;
			}
		}
		if (key == 'r' || key == 'R') explainrule();
		if (key == 'A' || key == 'a') {

			game(&p1, &p2, turn, overcount1, overcount2);
		}
	}
	return 0;
}

void start() {
	printf("player 1�� �г���(�ִ� 10��)�� �˷� �ּ���: ");
	scanf("%s", p1);
	printf("player 2�� �г���(�ִ� 10��)�� �˷� �ּ���: ");
	scanf("%s", p2);
	system("cls");

}

void map() {
	gotoxy(3, 2, "�����������������������������������������������������������");
	for (int i = 3; i < 57; i++) {
		gotoxy(3, i, "��                                                                                                                ��");
	}


	gotoxy(3, 57, "�����������������������������������������������������������");

	gotoxy(3, 60, "�����������������������������������������������������������");
	for (int i = 61; i < 67; i++) {
		gotoxy(3, i, "��                                                                                                                ��");
	}
	gotoxy(3, 67, "�����������������������������������������������������������");

	gotoxy(73, 3, "���� : S");

	gotoxy(73, 7, "��Ģ ���� : R");

	gotoxy(73, 11, "���� : X");

	gotoxy(73, 9, "���� : A");
	gotoxy(73, 17, "��Ȳ");
	gotoxy(73, 19, "������������������������������������������");
	for (int i = 20; i < 48; i++) {
		gotoxy(73, i, "��                                      ��                                      ��");
	}
	gotoxy(73, 48, "������������������������������������������");

	gotoxy(79, 23, "player 1 - ");
	printf("%s", p1);

	gotoxy(99, 23, "player 2 - ");
	printf("%s", p2);

	gotoxy(73, 51, "�� ������");
	gotoxy(73, 53, "������������������������������������������");
	for (int i = 54; i < 67; i++) {
		gotoxy(73, i, "��                                                                              ��");
	}
	gotoxy(73, 67, "������������������������������������������");
}

int yutrolling() {
	char y1[5];
	int yuti[5], upcount = 0, downcount = 0;
	srand(time(NULL));
	for (int i = 0; i < 4; i++) {
		yuti[i] = rand() % 2 + 1;
		if (yuti[i] == 1) {
			y1[i] = 'U';
			upcount++;
		}
		else if (yuti[i] == 2) {
			y1[i] = 'D';
			downcount++;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (y1[i] == 'U') {
			gotoxy(82 + 7 * (i - 1), 55, "������");
			gotoxy(82 + 7 * (i - 1), 56, "��      ��");
			gotoxy(82 + 7 * (i - 1), 57, "��   X  ��");
			gotoxy(82 + 7 * (i - 1), 58, "��      ��");
			gotoxy(82 + 7 * (i - 1), 59, "��      ��");
			gotoxy(82 + 7 * (i - 1), 60, "��   X  ��");
			gotoxy(82 + 7 * (i - 1), 61, "��      ��");
			gotoxy(82 + 7 * (i - 1), 62, "��      ��");
			gotoxy(82 + 7 * (i - 1), 63, "��   X  ��");
			gotoxy(82 + 7 * (i - 1), 64, "��      ��");
			gotoxy(82 + 7 * (i - 1), 65, "������");
		}

		else {
			gotoxy(82 + 7 * (i - 1), 55, "������");
			gotoxy(82 + 7 * (i - 1), 56, "��      ��");
			gotoxy(82 + 7 * (i - 1), 57, "��      ��");
			gotoxy(82 + 7 * (i - 1), 58, "��      ��");
			gotoxy(82 + 7 * (i - 1), 59, "��      ��");
			gotoxy(82 + 7 * (i - 1), 60, "��      ��");
			gotoxy(82 + 7 * (i - 1), 61, "��      ��");
			gotoxy(82 + 7 * (i - 1), 62, "��      ��");
			gotoxy(82 + 7 * (i - 1), 63, "��      ��");
			gotoxy(82 + 7 * (i - 1), 64, "��      ��");
			gotoxy(82 + 7 * (i - 1), 65, "������");
		}
	}
	gotoxy(102, 60, "-> ");
	switch (downcount) {
	case do:
		printf("��(1ĭ)            ");
		return do;
	case gae:
		printf("��(2ĭ)            ");
		return gae;
	case gul:
		printf("��(3ĭ)            ");
		return gul;
	case yut:
		printf("��(4ĭ+�ٽ� ������)");
		return yut;
	case mo:
		printf("��(5ĭ+�ٽ� ������)");
		return mo;
	}
}

void settings() {
	gotoxy(5, 61, "�� ���ӿ� ������ �ʿ����� �ǹ��� ��±���");
	gotoxy(5, 62, "�߰��� �־����� �ϴ� ����̳� �������� ������");
	gotoxy(5, 63, "1403 ��������� ���� �˷��ּ��� ����غ��Կ�");
	gotoxy(5, 65, "�ƹ� Ű�� ���� �ּ���!");

	while (1) {
		while (!kbhit()) {
			gotoxy(5, 65, "                                   ");
			Sleep(600);
			gotoxy(5, 65, "�ƹ� Ű�� ���� �ּ���!");
			Sleep(600);
		}
		if (kbhit())
			break;
	}
	gotoxy(5, 61, "                                             ");
	gotoxy(5, 62, "                                             ");
	gotoxy(5, 63, "                                             ");
	gotoxy(5, 65, "                                                ");
}

void explainrule() {

	gotoxy(5, 61, "���� ���� ");
	gotoxy(5, 62, "�� ������ �Ϲ����� �����̿� ���� ���� ���� ���� ������ �̵��� �� �ֽ��ϴ�");
	gotoxy(5, 63, "���� ������ ���� ���� ���� ���� ĭ�� ���� �� ��� ���� �̵��� �� �ְ�, ����� ���� ���� ��� ���� �� �ֽ��ϴ�");
	gotoxy(5, 64, "���� �������� ��� ���� ���޽�ų ��� �¸��մϴ�!");
	gotoxy(5, 66, "�����ϼ̴ٸ� �ƹ� Ű�� ���� �ּ���!");

	while (1) {
		while (!kbhit()) {
			gotoxy(5, 66, "                                   ");
			Sleep(600);
			gotoxy(5, 66, "�����ϼ̴ٸ� �ƹ� Ű�� ���� �ּ���!");
			Sleep(600);
		}
		if (kbhit())
			break;
	}
	gotoxy(5, 60, "         ");
	gotoxy(5, 61, "                                                                            ");
	gotoxy(5, 62, "                                                                                                             ");
	gotoxy(5, 63, "                                                 ");
	gotoxy(5, 65, "                                   ");
}

void pan() {
	gotoxy(4, 4, "      ������                                                                                ������");
	gotoxy(4, 5, "    ��          ��        ����            ����            ����            ����        ��          ��");
	gotoxy(4, 6, "    ��          ��      ��      ��        ��      ��        ��      ��        ��      ��      ��          ��");
	gotoxy(4, 7, "    ��          ��      ��      ��        ��      ��        ��      ��        ��      ��      ��          ��");
	gotoxy(4, 8, "    ��          ��      ��      ��        ��      ��        ��      ��        ��      ��      ��          ��");
	gotoxy(4, 9, "    ��          ��        ����            ����            ����            ����        ��          ��");
	gotoxy(4, 10, "      ������                                                                                ������");
	gotoxy(4, 13, "                        ����                                                    ����                    ");
	gotoxy(4, 14, "        ����        ��      ��                                                ��      ��        ����    ");
	gotoxy(4, 15, "      ��      ��      ��      ��                                                ��      ��      ��      ��  ");
	gotoxy(4, 16, "      ��      ��      ��      ��                                                ��      ��      ��      ��  ");
	gotoxy(4, 17, "      ��      ��        ����                                                    ����        ��      ��  ");
	gotoxy(4, 18, "        ����                                                                                    ����    ");
	gotoxy(4, 19, "                                      ����                          ����                                ");
	gotoxy(4, 20, "                                    ��      ��                      ��      ��                              ");
	gotoxy(4, 21, "                                    ��      ��                      ��      ��                              ");
	gotoxy(4, 22, "                                    ��      ��                      ��      ��                              ");
	gotoxy(4, 23, "        ����                        ����                          ����                      ����    ");
	gotoxy(4, 24, "      ��      ��                                                                                ��      ��  ");
	gotoxy(4, 25, "      ��      ��                                                                                ��      ��  ");
	gotoxy(4, 26, "      ��      ��                                                                                ��      ��  ");
	gotoxy(4, 27, "        ����                                      ������                                    ����    ");
	gotoxy(4, 28, "                                                  ��          ��                                            ");
	gotoxy(4, 29, "                                                  ��          ��                                            ");
	gotoxy(4, 30, "                                                  ��          ��                                            ");
	gotoxy(4, 31, "                                                  ��          ��                                            ");
	gotoxy(4, 32, "        ����                                    ��          ��                                  ����    ");
	gotoxy(4, 33, "      ��      ��                                    ������                                  ��      ��  ");
	gotoxy(4, 34, "      ��      ��                                                                                ��      ��  ");
	gotoxy(4, 35, "      ��      ��                      ����                          ����                    ��      ��  ");
	gotoxy(4, 36, "        ����                      ��      ��                      ��      ��                    ����    ");
	gotoxy(4, 37, "                                    ��      ��                      ��      ��                              ");
	gotoxy(4, 38, "                                    ��      ��                      ��      ��                              ");
	gotoxy(4, 39, "                                      ����                          ����                                ");
	gotoxy(4, 41, "        ����                                                                                    ����    ");
	gotoxy(4, 42, "      ��      ��        ����                                                      ����      ��      ��  ");
	gotoxy(4, 43, "      ��      ��      ��      ��                                                  ��      ��    ��      ��  ");
	gotoxy(4, 44, "      ��      ��      ��      ��                                                  ��      ��    ��      ��  ");
	gotoxy(4, 45, "        ����        ��      ��                                                  ��      ��      ����    ");
	gotoxy(4, 46, "                        ����                                                      ����                  ");
	gotoxy(4, 49, "      ������                                                                                ������  ");
	gotoxy(4, 50, "    ��          ��        ����            ����            ����              ����      ��          ��");
	gotoxy(4, 51, "    ��          ��      ��      ��        ��      ��        ��      ��          ��      ��    ��          ��");
	gotoxy(4, 52, "    ��          ��      ��      ��        ��      ��        ��      ��          ��      ��    ��          ��");
	gotoxy(4, 53, "    ��          ��      ��      ��        ��      ��        ��      ��          ��      ��    ��          ��");
	gotoxy(4, 54, "    ��          ��        ����            ����            ����              ����      ��          ��");
	gotoxy(4, 55, "      ������                                                                                ������  ");

}
void startmessage1() {
	gotoxy(5, 62, "p1�� ���Դϴ�!");
	gotoxy(5, 63, "���� �����̷��� ZŰ�� �����ּ���");
}
void startmessage2() {
	gotoxy(5, 62, "p2�� ���Դϴ�!");
	gotoxy(5, 63, "���� �����̷��� ZŰ�� �����ּ���");
}

void resetmessage() {
	gotoxy(5, 61, "                                                    ");
	gotoxy(5, 62, "                                                    ");
	gotoxy(5, 63, "                                                    ");
	gotoxy(5, 64, "                                                    ");
	gotoxy(5, 65, "                                                    ");
	gotoxy(5, 66, "                                                    ");
}

void reset(team* a1, team* a2) {
	for (int i = 1; i < 5; i++) {
		a1->mal[i].loc = 1;
		a1->mal[i].over = 0;
		a2->mal[i].loc = 1;
		a2->mal[i].over = 0;
	}
}

void hidecursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

int game(team* p1, team* p2, int turn, int overcount1, int overcount2) {
	int key, sel, kan, ans;// beforekan�� �����ϴ� ������ 11�� ������ �밢�� ��ο��� 23�� 28�� �� �ְ� �ϱ� ���ؼ��̴�.
	resetmessage();
	gotoxy(1, 1, "");
	printf("%d %d %d %d", p1->mal[1].loc, p1->mal[2].loc, p1->mal[3].loc, p1->mal[4].loc);

	if (turn == 1) startmessage1();
	else if (turn == 2) startmessage2();
	Sleep(1000);

	kan = yutrolling();
	while (1) {
		key = getKeyDown();

		if (key == 'z' || key == 'Z') {
			resetmessage();
			Sleep(700);
		A:
			switch (kan)
			{
				resetmessage();
			case do:
				gotoxy(5, 61, "���� ���Խ��ϴ�.");
				gotoxy(5, 62, "� ���� �����̽ðڽ��ϱ�? (1, 2, 3, 4)\n");
				gotoxy(5, 63, "");
				scanf("%d", &sel);
				resetmessage();
				if (turn == 1 && p1->mal[sel].over != 1) {
					if (p1->mal[sel].loc == 6 || p1->mal[sel].loc == 11) {
						gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
						gotoxy(5, 62, "");
						scanf("%d", &ans);
						if (ans == 2) {
							p1->mal[sel].loc++;
							beforekan1[sel] = p1->mal[sel].loc - 1;
						}
						else if (ans == 1) {
							if (p1->mal[sel].loc == 6) {
								p1->mal[sel].loc = 21;
								beforekan1[sel] = 6;
							}
							if (p1->mal[sel].loc == 11) {
								p1->mal[sel].loc = 26;
								beforekan1[sel] = 11;
							}

						}
					}
					if (p1->mal[sel].loc == 25) {
						p1->mal[sel].loc = 16;
						beforekan1[sel] = 25;
					}
					if (p1->mal[sel].loc == 23) {
						if (beforekan1[sel] == 22 || beforekan1[sel] == 21 || beforekan1[sel] == 6 || beforekan1[sel] == 5 || beforekan1[sel] == 4) {
							gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
							gotoxy(5, 62, "");
							scanf("%d", &ans);
							if (ans == 2) {
								p1->mal[sel].loc++;
								beforekan1[sel] = 23;
							}
							else if (ans == 1) {
								p1->mal[sel].loc = 21;
								beforekan1[sel] = 6;

							}
						}
						if (beforekan1[sel] == 27 || beforekan1[sel] == 26 || beforekan1[sel] == 11 || beforekan1[sel] == 10 || beforekan1[sel] == 9) {
							p1->mal[sel].loc = 28;
							beforekan1[sel] = 23;
						}
					}
					else if (p1->mal[sel].loc == 29 || p1->mal[sel].loc == 20) {
						gotoxy(5, 61, "�������� �����߽��ϴ�!");
						Sleep(500);
						resetmessage();
						p1->mal[sel].over = 1;
						overcount1++;
					}
					else p1->mal[sel].loc += do;
				}

				if (turn == 2 && p2->mal[sel].over != 1) {
					if (p2->mal[sel].loc == 6 || p2->mal[sel].loc == 11) {
						gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
						gotoxy(5, 62, "");
						scanf("%d", &ans);
						if (ans == 2) {
							p2->mal[sel].loc++;
							beforekan2[sel] = p2->mal[sel].loc - 1;
						}
						else if (ans == 1) {
							if (p2->mal[sel].loc == 6) {
								p2->mal[sel].loc = 21;
								beforekan2[sel] = 6;
							}
							if (p2->mal[sel].loc == 11) {
								p2->mal[sel].loc = 26;
								beforekan2[sel] = 11;
							}

						}
					}
					if (p2->mal[sel].loc == 25) {
						p2->mal[sel].loc = 16;
						beforekan2[sel] = 25;
					}
					if (p2->mal[sel].loc == 23) {
						if (beforekan2[sel] == 22 || beforekan2[sel] == 21 || beforekan2[sel] == 6 || beforekan2[sel] == 5 || beforekan2[sel] == 4) {
							gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
							gotoxy(5, 62, "");
							scanf("%d", &ans);
							if (ans == 2) {
								p2->mal[sel].loc++;
								beforekan2[sel] = 23;
							}
							else if (ans == 1) {

								p2->mal[sel].loc = 21;
								beforekan2[sel] = 6;

							}
						}
						if (beforekan2[sel] == 27 || beforekan2[sel] == 26 || beforekan2[sel] == 11 || beforekan2[sel] == 10 || beforekan2[sel] == 9) {
							p2->mal[sel].loc = 28;
							beforekan2[sel] = 23;
						}
					}
					else if (p2->mal[sel].loc == 29 || p2->mal[sel].loc == 20) {
						gotoxy(5, 61, "�������� �����߽��ϴ�!");
						Sleep(500);
						resetmessage();
						p2->mal[sel].over = 1;
						overcount2++;
					}
					else p2->mal[sel].loc += do;
				}
				printmal(&p1, &p2);
				if (overcount1 != 4 && overcount2 != 4) {
					if (turn == 1) turn = 2;
					else if (turn == 2)turn = 1;
					game(&p1, &p2, turn, overcount1, overcount2);
				}
				else if (overcount1 == 4) {
					endmessage(&p1);
				}
				else if (overcount2 == 4) {
					endmessage(&p2);
				}

				break;

			case gae://������� �ؾ� ��, �Ұ� ��������
				gotoxy(5, 61, "���� ���Խ��ϴ�.");
				gotoxy(5, 62, "� ���� �����̽ðڽ��ϱ�? (1, 2, 3, 4)\n");
				gotoxy(5, 63, "");
				scanf("%d", &sel);
				resetmessage();
				if (turn == 1 && p1->mal[sel].over != 1) {
					if (p1->mal[sel].loc == 6 || p1->mal[sel].loc == 11) {
						gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
						gotoxy(5, 62, "");
						scanf("%d", &ans);
						if (ans == 2) {
							p1->mal[sel].loc += 2;
							beforekan1[sel] = p1->mal[sel].loc - 2;
						}
						else if (ans == 1) {
							if (p1->mal[sel].loc == 6) {
								p1->mal[sel].loc = 22;
								beforekan1[sel] = 6;
							}
							if (p1->mal[sel].loc == 11) {
								p1->mal[sel].loc = 26;
								beforekan1[sel] = 11;
							}

						}
					}
					if (p1->mal[sel].loc == 25) {
						p1->mal[sel].loc = 17;
						beforekan1[sel] = 25;
					}
					if (p1->mal[sel].loc == 24) {
						p1->mal[sel].loc = 16;
						beforekan1[sel] = 24;
					}
					if (p1->mal[sel].loc == 27) {
						p1->mal[sel].loc = 28;
					}
					if (p1->mal[sel].loc == 23) {
						if (beforekan1[sel] == 22 || beforekan1[sel] == 21 || beforekan1[sel] == 6 || beforekan1[sel] == 5 || beforekan1[sel] == 4) {
							gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
							gotoxy(5, 62, "");
							scanf("%d", &ans);
							if (ans == 2) {
								p1->mal[sel].loc += 2;
								beforekan1[sel] = 23;
								Sleep(500);
								resetmessage();
							}
							else if (ans == 1) {
								Sleep(500);
								resetmessage();
								p1->mal[sel].loc = 21;
								beforekan1[sel] = 6;

							}
						}
						if (beforekan1[sel] == 27 || beforekan1[sel] == 26 || beforekan1[sel] == 11 || beforekan1[sel] == 10 || beforekan1[sel] == 9) {
							p1->mal[sel].loc = 28;
							beforekan1[sel] = 23;
						}
					}
					else if (p1->mal[sel].loc == 29 || p1->mal[sel].loc == 20 || p1->mal[sel].loc == 28 || p1->mal[sel].loc == 19) {
						gotoxy(5, 61, "�������� �����߽��ϴ�!");
						Sleep(500);
						resetmessage();
						p1->mal[sel].over = 1;
						overcount1++;
					}
					else p1->mal[sel].loc += gae;
				}
				if (turn == 2 && p2->mal[sel].over != 1) {
					if (p2->mal[sel].loc == 6 || p2->mal[sel].loc == 11) {
						gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
						gotoxy(5, 62, "");
						scanf("%d", &ans);
						if (ans == 2) {
							Sleep(500);
							resetmessage();
							p2->mal[sel].loc += 2;
							beforekan2[sel] = p2->mal[sel].loc - 2;
						}
						else if (ans == 1) {
							Sleep(500);
							resetmessage();
							if (p2->mal[sel].loc == 6) {
								p2->mal[sel].loc = 22;
								beforekan2[sel] = 6;
							}
							if (p2->mal[sel].loc == 11) {
								p2->mal[sel].loc = 26;
								beforekan2[sel] = 11;
							}

						}
					}
					if (p2->mal[sel].loc == 25) {
						p2->mal[sel].loc = 17;
						beforekan2[sel] = 25;
					}
					if (p2->mal[sel].loc == 24) {
						p2->mal[sel].loc = 16;
						beforekan2[sel] = 24;
					}
					if (p2->mal[sel].loc == 27) {
						p2->mal[sel].loc = 28;
					}
					if (p2->mal[sel].loc == 23) {
						if (beforekan2[sel] == 22 || beforekan2[sel] == 21 || beforekan2[sel] == 6 || beforekan2[sel] == 5 || beforekan2[sel] == 4) {
							gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
							gotoxy(5, 62, "");
							scanf("%d", &ans);
							if (ans == 2) {
								Sleep(500);
								resetmessage();
								p2->mal[sel].loc += 2;
								beforekan2[sel] = 23;
							}
							else if (ans == 1) {
								Sleep(500);
								resetmessage();
								p2->mal[sel].loc = 21;
								beforekan2[sel] = 6;

							}
						}
						if (beforekan2[sel] == 27 || beforekan2[sel] == 26 || beforekan2[sel] == 11 || beforekan2[sel] == 10 || beforekan2[sel] == 9) {
							p2->mal[sel].loc = 28;
							beforekan2[sel] = 23;
						}
					}
					else if (p2->mal[sel].loc == 29 || p2->mal[sel].loc == 20 || p2->mal[sel].loc == 28 || p2->mal[sel].loc == 19) {
						gotoxy(5, 61, "�������� �����߽��ϴ�!");
						Sleep(500);
						resetmessage();
						p2->mal[sel].over = 1;
						overcount2++;
					}
					else p2->mal[sel].loc += gae;
				}
				printmal(&p1, &p2);
				if (overcount1 != 4 && overcount2 != 4) {
					if (turn == 1) turn = 2;
					else if (turn == 2)turn = 1;
					game(&p1, &p2, turn, overcount1, overcount2);
				}
				else if (overcount1 == 4) {
					endmessage(&p1);
				}
				else if (overcount2 == 4) {
					endmessage(&p2);
				}
				break;
			case gul:
				gotoxy(5, 61, "���� ���Խ��ϴ�.");
				gotoxy(5, 62, "� ���� �����̽ðڽ��ϱ�? (1, 2, 3, 4)\n");
				gotoxy(5, 63, "");
				scanf("%d", &sel);
				resetmessage();
				if (turn == 1 && p1->mal[sel].over != 1) {
					if (p1->mal[sel].loc == 6 || p1->mal[sel].loc == 11) {
						gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
						gotoxy(5, 62, "");
						scanf("%d", &ans);
						if (ans == 2) {
							Sleep(500);
							resetmessage();
							p1->mal[sel].loc += 3;
							beforekan1[sel] = p1->mal[sel].loc - 3;
						}
						else if (ans == 1) {
							Sleep(500);
							resetmessage();
							if (p1->mal[sel].loc == 6) {
								p1->mal[sel].loc = 23;
								beforekan1[sel] = 6;
							}
							if (p1->mal[sel].loc == 11) {
								p1->mal[sel].loc = 23;
								beforekan1[sel] = 11;
							}

						}
					}
					if (p1->mal[sel].loc == 25) {
						p1->mal[sel].loc = 18;
						beforekan1[sel] = 25;
					}
					if (p1->mal[sel].loc == 24) {
						p1->mal[sel].loc = 17;
						beforekan1[sel] = 24;
					}

					if (p1->mal[sel].loc == 27) {
						p1->mal[sel].loc = 29;
					}
					if (p1->mal[sel].loc == 23) {
						if (beforekan1[sel] == 22 || beforekan1[sel] == 21 || beforekan1[sel] == 6 || beforekan1[sel] == 5 || beforekan1[sel] == 4) {
							gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
							gotoxy(5, 62, "");
							scanf("%d", &ans);
							Sleep(500);
							resetmessage();
							if (ans == 1) {
								p1->mal[sel].over = 1;
								overcount1++;
							}
							else if (ans == 2) {
								p1->mal[sel].loc = 16;
								beforekan1[sel] = 23;
							}
						}
						if (beforekan1[sel] == 27 || beforekan1[sel] == 26 || beforekan1[sel] == 11 || beforekan1[sel] == 10 || beforekan1[sel] == 9) {
							p1->mal[sel].over = 1;
							overcount1++;
						}
					}
					else if (p1->mal[sel].loc == 29 || p1->mal[sel].loc == 20 || p1->mal[sel].loc == 28 || p1->mal[sel].loc == 19 || p1->mal[sel].loc == 17) {
						gotoxy(5, 61, "�������� �����߽��ϴ�!");
						Sleep(500);
						resetmessage();
						p1->mal[sel].over = 1;
						overcount1++;
					}
					else p1->mal[sel].loc += gul;
				}
				if (turn == 2 && p2->mal[sel].over != 1) {
					if (p2->mal[sel].loc == 6 || p2->mal[sel].loc == 11) {
						gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
						gotoxy(5, 62, "");
						scanf("%d", &ans);
						Sleep(500);
						resetmessage();
						if (ans == 2) {
							p2->mal[sel].loc += 3;
							beforekan2[sel] = p2->mal[sel].loc - 3;
						}
						else if (ans == 1) {
							if (p2->mal[sel].loc == 6) {
								p2->mal[sel].loc = 23;
								beforekan2[sel] = 6;
							}
							if (p2->mal[sel].loc == 11) {
								p2->mal[sel].loc = 23;
								beforekan2[sel] = 11;
							}

						}
					}
					if (p2->mal[sel].loc == 25) {
						p2->mal[sel].loc = 17;
						beforekan2[sel] = 25;
					}
					if (p2->mal[sel].loc == 24) {
						p2->mal[sel].loc = 16;
					}
					if (p2->mal[sel].loc == 27) {
						p2->mal[sel].loc = 28;
					}
					if (p2->mal[sel].loc == 23) {
						if (beforekan2[sel] == 22 || beforekan2[sel] == 21 || beforekan2[sel] == 6 || beforekan2[sel] == 5 || beforekan2[sel] == 4) {
							gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
							gotoxy(5, 62, "");
							scanf("%d", &ans);
							Sleep(500);
							resetmessage();
							if (ans == 1) {
								p2->mal[sel].over = 1;
								overcount2++;
							}
							else if (ans == 2) {

								p2->mal[sel].loc = 16;
								beforekan2[sel] = 23;

							}
						}
						if (beforekan2[sel] == 27 || beforekan2[sel] == 26 || beforekan2[sel] == 11 || beforekan2[sel] == 10 || beforekan2[sel] == 9) {
							p2->mal[sel].over = 1;
							overcount2++;
						}
					}
					else if (p2->mal[sel].loc == 29 || p2->mal[sel].loc == 20 || p2->mal[sel].loc == 28 || p2->mal[sel].loc == 19 || p2->mal[sel].loc == 18) {
						gotoxy(5, 61, "�������� �����߽��ϴ�!");
						Sleep(500);
						resetmessage();
						p2->mal[sel].over = 1;
						overcount2++;
					}
					else p2->mal[sel].loc += gul;
				}
				printmal(&p1, &p2);
				if (overcount1 != 4 && overcount2 != 4) {
					if (turn == 1) turn = 2;
					else if (turn == 2)turn = 1;
					game(&p1, &p2, turn, overcount1, overcount2);
				}
				else if (overcount1 == 4) {
					endmessage(&p1);
				}
				else if (overcount2 == 4) {
					endmessage(&p2);
				}
				break;
			case yut:
				gotoxy(5, 61, "���� ���Խ��ϴ�.");
				gotoxy(5, 62, "� ���� �����̽ðڽ��ϱ�? (1, 2, 3, 4)\n");
				gotoxy(5, 63, "");
				scanf("%d", &sel);
				resetmessage();
				if (turn == 1 && p1->mal[sel].over != 1) {
					if (p1->mal[sel].loc == 6 || p1->mal[sel].loc == 11) {
						gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
						gotoxy(5, 62, "");
						scanf("%d", &ans);
						Sleep(500);
						resetmessage();
						if (ans == 2) {
							p1->mal[sel].loc += 4;
							beforekan1[sel] = p1->mal[sel].loc - 4;
						}
						else if (ans == 1) {
							if (p1->mal[sel].loc == 6) {
								p1->mal[sel].loc = 24;
								beforekan1[sel] = 6;
							}
							if (p1->mal[sel].loc == 11) {
								p1->mal[sel].loc = 28;
								beforekan1[sel] = 11;
							}

						}
					}
					if (p1->mal[sel].loc == 25) {
						p1->mal[sel].loc = 19;
						beforekan1[sel] = 25;
					}
					if (p1->mal[sel].loc == 24) {
						p1->mal[sel].loc = 18;
						beforekan1[sel] = 24;
					}
					if (p1->mal[sel].loc == 22) {
						p1->mal[sel].loc = 16;
						beforekan1[sel] = 22;
					}
					if (p1->mal[sel].loc == 26) {
						p1->mal[sel].loc = 29;
					}
					if (p1->mal[sel].loc == 27) {
						p1->mal[sel].over = 1;
						overcount1++;
					}
					if (p1->mal[sel].loc == 23) {
						if (beforekan1[sel] == 22 || beforekan1[sel] == 21 || beforekan1[sel] == 6 || beforekan1[sel] == 5 || beforekan1[sel] == 4) {
							gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
							gotoxy(5, 62, "");
							scanf("%d", &ans);
							Sleep(500);
							resetmessage();
							if (ans == 1) {
								p1->mal[sel].over = 1;
								overcount1++;
							}
							else if (ans == 2) {
								p1->mal[sel].loc = 17;
								beforekan1[sel] = 23;
							}
						}
						if (beforekan1[sel] == 27 || beforekan1[sel] == 26 || beforekan1[sel] == 11 || beforekan1[sel] == 10 || beforekan1[sel] == 9) {
							p1->mal[sel].over = 1;
							overcount1++;
						}
					}
					else if (p1->mal[sel].loc == 29 || p1->mal[sel].loc == 20 || p1->mal[sel].loc == 28 || p1->mal[sel].loc == 19 || p1->mal[sel].loc == 17) {
						gotoxy(5, 61, "�������� �����߽��ϴ�!");
						Sleep(500);
						resetmessage();
						p1->mal[sel].over = 1;
						overcount1++;
					}
					else p1->mal[sel].loc += yut;
				}
				if (turn == 2 && p2->mal[sel].over != 1) {
					if (p2->mal[sel].loc == 6 || p2->mal[sel].loc == 11) {
						gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
						gotoxy(5, 62, "");
						scanf("%d", &ans);
						Sleep(500);
						resetmessage();
						if (ans == 2) {
							p2->mal[sel].loc += 4;
							beforekan2[sel] = p2->mal[sel].loc - 4;
						}
						else if (ans == 1) {
							if (p2->mal[sel].loc == 6) {
								p2->mal[sel].loc = 24;
								beforekan2[sel] = 6;
							}
							if (p2->mal[sel].loc == 11) {
								p2->mal[sel].loc = 28;
								beforekan2[sel] = 11;
							}

						}
					}
					if (p2->mal[sel].loc == 25) {
						p2->mal[sel].loc = 17;
						beforekan2[sel] = 25;
					}
					if (p2->mal[sel].loc == 24) {
						p2->mal[sel].loc = 16;
					}
					if (p2->mal[sel].loc == 22) {
						p2->mal[sel].loc = 16;
						beforekan2[sel] = 22;
					}
					if (p2->mal[sel].loc == 27) {
						p2->mal[sel].over = 1;
						overcount2++;
					}
					if (p2->mal[sel].loc == 23) {
						if (beforekan2[sel] == 22 || beforekan2[sel] == 21 || beforekan2[sel] == 6 || beforekan2[sel] == 5 || beforekan2[sel] == 4) {
							gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
							gotoxy(5, 62, "");
							scanf("%d", &ans);
							Sleep(500);
							resetmessage();
							if (ans == 1) {
								p2->mal[sel].over = 1;
								overcount2++;
							}
							else if (ans == 2) {

								p2->mal[sel].loc = 17;
								beforekan2[sel] = 23;

							}
						}
						if (beforekan2[sel] == 27 || beforekan2[sel] == 26 || beforekan2[sel] == 11 || beforekan2[sel] == 10 || beforekan2[sel] == 9) {
							p2->mal[sel].over = 1;
							overcount2++;
						}
					}
					else if (p2->mal[sel].loc == 29 || p2->mal[sel].loc == 20 || p2->mal[sel].loc == 28 || p2->mal[sel].loc == 19 || p2->mal[sel].loc == 18) {
						gotoxy(5, 61, "�������� �����߽��ϴ�!");
						Sleep(500);
						resetmessage();
						p2->mal[sel].over = 1;
						overcount2++;
					}

					else p2->mal[sel].loc += yut;
				}
				printmal(&p1, &p2);
				gotoxy(5, 62, "�ٽ� ���� �� �ֽ��ϴ�!");
				Sleep(500);
				if (overcount1 != 4 && overcount2 != 4) {
					game(&p1, &p2, turn, overcount1, overcount2);
				}
				else if (overcount1 == 4) {
					endmessage(&p1);
				}
				else if (overcount2 == 4) {
					endmessage(&p2);
				}
				break;
			case mo:
				gotoxy(5, 61, "�� ���Խ��ϴ�");
				gotoxy(5, 62, "� ���� �����̽ðڽ��ϱ�? (1, 2, 3, 4)\n");
				gotoxy(5, 63, "");
				scanf("%d", &sel);
				resetmessage();
				//���� ���� �����̴� �� ����
				if (turn == 1 && p1->mal[sel].over != 1) {
					if (p1->mal[sel].loc == 6 || p1->mal[sel].loc == 11) {
						gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
						gotoxy(5, 62, "");
						scanf("%d", &ans);
						Sleep(500);
						resetmessage();
						if (ans == 2) {
							p1->mal[sel].loc += 5;
							beforekan1[sel] = p1->mal[sel].loc - 5;
						}
						else if (ans == 1) {
							if (p1->mal[sel].loc == 6) {
								p1->mal[sel].loc = 25;
								beforekan1[sel] = 6;
							}
							if (p1->mal[sel].loc == 11) {
								p1->mal[sel].loc = 29;

							}

						}
					}
					if (p1->mal[sel].loc == 25) {
						p1->mal[sel].loc = 20;
						beforekan1[sel] = 25;
					}
					if (p1->mal[sel].loc == 24) {
						p1->mal[sel].loc = 19;
						beforekan1[sel] = 24;
					}
					if (p1->mal[sel].loc == 22) {
						p1->mal[sel].loc = 18;
						beforekan1[sel] = 22;
					}
					if (p1->mal[sel].loc == 21) {
						p1->mal[sel].loc = 16;
						beforekan1[sel] = 22;
					}

					if (p1->mal[sel].loc == 23) {
						if (beforekan1[sel] == 22 || beforekan1[sel] == 21 || beforekan1[sel] == 6 || beforekan1[sel] == 5 || beforekan1[sel] == 4) {
							gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
							gotoxy(5, 62, "");
							scanf("%d", &ans);
							Sleep(500);
							resetmessage();
							if (ans == 1) {
								p1->mal[sel].over = 1;
								overcount1++;
							}
							else if (ans == 2) {
								p1->mal[sel].loc = 18;
								beforekan1[sel] = 23;
							}
						}
						if (beforekan1[sel] == 27 || beforekan1[sel] == 26 || beforekan1[sel] == 11 || beforekan1[sel] == 10 || beforekan1[sel] == 9) {
							p1->mal[sel].over = 1;
							overcount1++;
						}
					}
					else if (p1->mal[sel].loc == 29 || p1->mal[sel].loc == 20 || p1->mal[sel].loc == 28 || p1->mal[sel].loc == 19 || p1->mal[sel].loc == 17 || p1->mal[sel].loc == 16 || p1->mal[sel].loc == 26 || p1->mal[sel].loc == 27) {
						gotoxy(5, 61, "�������� �����߽��ϴ�!");
						Sleep(500);
						resetmessage();
						p1->mal[sel].over = 1;
						overcount1++;
					}
					else p1->mal[sel].loc += mo;
				}
				if (turn == 2 && p2->mal[sel].over != 1) {
					if (p2->mal[sel].loc == 6 || p2->mal[sel].loc == 11) {
						gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
						gotoxy(5, 62, "");
						scanf("%d", &ans);
						Sleep(500);
						resetmessage();
						if (ans == 2) {
							p2->mal[sel].loc += 5;
							beforekan2[sel] = p2->mal[sel].loc - 5;
						}
						else if (ans == 1) {
							if (p2->mal[sel].loc == 6) {
								p2->mal[sel].loc = 25;
								beforekan2[sel] = 6;
							}
							if (p2->mal[sel].loc == 11) {
								p2->mal[sel].loc = 29;
								beforekan2[sel] = 11;
							}

						}
					}
					if (p2->mal[sel].loc == 25) {
						p2->mal[sel].loc = 20;
						beforekan2[sel] = 25;
					}
					if (p2->mal[sel].loc == 24) {
						p2->mal[sel].loc = 19;
					}
					if (p2->mal[sel].loc == 22) {
						p2->mal[sel].loc = 17;
						beforekan2[sel] = 22;
					}
					if (p2->mal[sel].loc == 21) {
						p2->mal[sel].loc = 16;
						beforekan2[sel] = 22;
					}
					if (p2->mal[sel].loc == 23) {
						if (beforekan2[sel] == 22 || beforekan2[sel] == 21 || beforekan2[sel] == 6 || beforekan2[sel] == 5 || beforekan2[sel] == 4) {
							gotoxy(5, 61, "������ �ٲٽðڽ��ϱ�? (��: 1, �ƴϿ�:2)");
							gotoxy(5, 62, "");
							scanf("%d", &ans);
							Sleep(500);
							resetmessage();
							if (ans == 1) {
								p2->mal[sel].over = 1;
								overcount2++;
							}
							else if (ans == 2) {
								p2->mal[sel].loc = 18;
								beforekan2[sel] = 23;
							}
						}
						if (beforekan2[sel] == 27 || beforekan2[sel] == 26 || beforekan2[sel] == 11 || beforekan2[sel] == 10 || beforekan2[sel] == 9) {
							p2->mal[sel].over = 1;
							overcount2++;
						}
					}
					else if (p2->mal[sel].loc == 29 || p2->mal[sel].loc == 20 || p2->mal[sel].loc == 28 || p2->mal[sel].loc == 19 || p2->mal[sel].loc == 17 || p2->mal[sel].loc == 16 || p2->mal[sel].loc == 26 || p2->mal[sel].loc == 27) {
						gotoxy(5, 61, "�������� �����߽��ϴ�!");
						Sleep(500);
						resetmessage();
						p2->mal[sel].over = 1;
						overcount2++;
					}
					else p2->mal[sel].loc += mo;
				}
				gotoxy(5, 62, "�ٽ� ���� �� �ֽ��ϴ�!");
				Sleep(500);
				printmal(&p1, &p2);
				if (overcount1 != 4 && overcount2 != 4) {
					game(&p1, &p2, turn, overcount1, overcount2);
				}
				else if (overcount1 == 4) {
					endmessage(&p1);
				}
				else if (overcount2 == 4) {
					endmessage(&p2);
				}
				break;
			default:
				resetmessage();
				gotoxy(5, 62, "�ٽ� �Է��� �ֽʽÿ�");
				goto A;
			}

		}

	}

}
//11 10  9  8  7  6
//12 26        21 5
//13   27   22    4
//14     23       3
//15   24   28    2
//  25         29
//16 17 18 19  20 1