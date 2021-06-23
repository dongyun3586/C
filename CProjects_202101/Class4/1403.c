#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define X 3
#define Y 2

int x[200], y[200];
int appleX, appleY;//먹이 좌표
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
	hard = mode();//난이도 받기
	title(hard);

	while (1) {
		key = getch();//키값을 받는다.
		Sleep(speed);//속도만큼 멈췄다 시작하기

		switch (key) {
		case 'w':
		case 'a':
		case 's':
		case 'd':
			if ((way == 'w' && key != 's') || (way == 'd' && key != 'a') || (way == 'a' && key != 'd') || (way == 's' && key != 'w')) {
				way = key;//방향이 반대 방향 가는 거 방지
			}
			key = 0;
			break;
		case 'p'://정지 상태
			pause();
			break;
		case 'x':
			exit(0);//프로그램 종료
		}
		move(way);
	}
}
void move(int way) {
	int i;
	if (x[0] == appleX && y[0] == appleY) {//사과 먹었을 때
		score += 100;
		apple();
		length++;
	}
	if (x[0] == 0 || x[0] == width - 1 || y[0] == 0 || y[0] == height - 1) {
		gameover();// 벽에 박았을 때
		return;

	}
	for (i = 1; i < length; i++) {
		if (x[0] == x[i] && y[0] == y[i]) {//자기 몸통에 머리박았을 때
			gameover();
			return;
		}
	}

	gotoxy(X + x[length - 1], Y + y[length - 1], "  ");//뱀의 끝 좌표를 없앤다.
	for (i = length - 1; i > 0; i--) {//뱀의 몸통을 한 좌표 위씩으로 옮긴다.
		x[i] = x[i - 1];
		y[i] = y[i - 1];
	}
	gotoxy(X + x[0], Y + y[0], "□");//뱀의 몸통
	if (way == 'a') --x[0];
	if (way == 'd') ++x[0];
	if (way == 'w') --y[0];
	if (way == 's') ++y[0];
	gotoxy(X + x[i], Y + y[i], "■");//뱀의 머리
}

void title(int hard) {
	switch (hard) {
	case 1://제일 쉬움
		width = 40;
		height = 30;
		title2();
		break;
	case 2://보통
		width = 32;
		height = 24;
		title2();
		break;
	case 3://어려움
		width = 32;
		height = 24;
		speed -= 5;
		title2();
		break;
	case 4://극악
		width = 24;
		height = 18;
		speed -= 7;
		title2();
		break;
	}
}
void title2() {
	DoSome();//로딩창 출력
	system("cls");//로딩창 지움
	printf("LOADING COMPLETE!!");
	Sleep(300);//잠시 멈춤
	system("cls");
	map();//맵 그리기
	for (int i = Y + 1; i < Y + height - 1; i++) {
		for (int j = X + 1; j < X + width - 1; j++) gotoxy(j, i, "  ");
	}
	gotoxy(X + (width / 2) - 7, Y + 5, "+--------------------------+");
	gotoxy(X + (width / 2) - 7, Y + 6, "|        S N A K E         |");
	gotoxy(X + (width / 2) - 7, Y + 7, "+--------------------------+");

	gotoxy(X + (width / 2) - 7, Y + 9, "  - 아무 키나 눌러 시작 - ");

	gotoxy(X + (width / 2) - 7, Y + 11, "   - w,a,s,d : Move    ");
	gotoxy(X + (width / 2) - 7, Y + 12, "   - p : Pause             ");
	gotoxy(X + (width / 2) - 7, Y + 13, "   - x : Quit              ");//시작화면
	while (1) {
		if (kbhit()) {
			key = getch();
			if (key == 'x')
				exit(0);
			else
				break;
		}
		gotoxy(X + (width / 2) - 7, Y + 9, " - 아무 키나 눌러 시작 - ");
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

	way = 'a';    //왼쪽으로 리셋
	length = 5;
	score = 0;
	for (i = 0; i < length; i++) {
		x[i] = width / 2 + i;
		y[i] = height / 2;
		gotoxy(X + x[i], Y + y[i], "□");
	}
	gotoxy(X + x[0], Y + y[0], "■");
	apple();
}
int mode() {
	int ans;
A:
	printf("어떤 모드에서 하시겠습니까?\n");
	printf("1. 쉬움\n");
	printf("2. 보통\n");
	printf("3. 어려움\n");
	printf("4. 이게 사람이 할 수준이냐?\n");
	scanf("%d", &ans);
	if (ans != 1 && ans != 2 && ans != 3 && ans != 4) {
		system("cls");
		printf("다시 선택해주십시오\n");
		goto A;
	}
	system("cls");
	return ans;
}
void map() {//설정한 width와 height값의 평면 안의 공간을 모두 네모로 채움
	for (int i = 0; i < width; i++) {
		gotoxy(X + i, Y, "■");
	}
	for (int i = Y + 1; i < Y + height - 1; i++) {
		gotoxy(X, i, "■");
		gotoxy(X + width - 1, i, "■");
	}
	for (int i = 0; i < width; i++) {
		gotoxy(X + i, Y + height - 1, "■");
	}
}
void gotoxy(int x, int y, char* s) {//인터넷에서 가지고 옴
	COORD pos = { 2 * x,y };//게임에서 한 칸이 2바이트 이므로 *2해줌
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
				crush = 1;//사과가 몸에서 스폰될 때
				break;
			}
		}

		if (crush == 1)
			continue;

		gotoxy(X + appleX, Y + appleY, "*");//충돌 시 재생성
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

void pause() {//정지
	while (1) {
		if (key == 'p') {
			gotoxy(X + (width / 2) - 9, Y, "< PAUSE : PRESS ANY KEY TO RESUME > ");
			Sleep(400);
			gotoxy(X + (width / 2) - 9, Y, "                                    ");
			Sleep(400);//깜빡깜빡
		}
		else {
			map();
			return;
		}
		if (kbhit())
			key = getch();

	}
}
void DoSome()//로딩창
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

}//인터넷에서 가져옴, 출처: https://twinw.tistory.com/200 [흰고래의꿈]

void DoProgress(char label[], int step, int total)//로딩
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
	for (int i = 0; i < pos; i++)  printf("%c", '=');//=을 채워 로딩바처럼 적음

	//fill progress bar with spaces
	printf("% *c", width - pos + 1, ']');
	printf(" %3d%%\r", percent);

	//reset text color, only on Windows
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08);
}


