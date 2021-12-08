#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <stdbool.h> // 불리언 자료형 (참, 거짓을 판단하는 자료형) 사용을 위한 헤더파일
#include <windows.h>
#define _CRT_NONSTDC_NO_WARNINGS //conio 쓸때 생기는 에러 방지용
#define _CRT_SECURE_NO_WARNINGS  //fopen 사용시 발생할 수 있는 에러 방지용
#pragma warning(disable : 4996)  //얘도 권장되지 않은 함수시 발생할 수 있는 에러 방지용
#include <conio.h> // getch 등으로 내가 누른 키가 어떤 키인지 판별하기 위한 헤더 파일
#define Xstart 8   //기본 x좌표 (처음 블럭 나올시)
#define Ystart 0   //기본 y좌표 (처음 블럭 나올시)
clock_t Dropstart, Dropend, Reachground; //시간의 흐름을 나타내는 구조체 및 함수 
//clock은 밀리초 단위이고 프로그램 시작 후 지금까지 얼마의 시간이 지났는지 return하는 함수이다
//Dropstart는 블럭이 떨어지기 시작한 시간을 Dropend는 블럭이 떨어지기 위한 시간 조절에 사용, Reachground는 블럭이 바닥에 닿은 후 얼마의 시간이 흘렀는지
int x = Xstart;
int y = Ystart;
int k;            //중간점검시 계속해서 블럭을 이동시키거나 회전시킬시 시간이 초기화되서 바닥에서 무한히 비비는 것이 가능했음 이 현상을 막기 위한 변수
int harddrop;     //하드드롭을 실행하기 위해 사용하는 변수
int newblock;     //현재 떨어지는 블럭 및 다음 블럭을 위해 사용하는 변수
int nextblock;    //다음 블럭을 알리기 위해 사용하는 변수
int Rotation = 0; //회전을 판별
int key;          //방향키 관련 변수
int flag;         //계속해서 맵 전체 초기화 후 출력을 하다보니 너무 심하게 깜박이는 현상 발견 이 현상을 줄이기 위해 한 턴이 끝났음을 flag변수를 통해 인지하여 맵 초기화를 최소화하여 깜박임을 줄임
int END;          //게임의 종료 조건 판별 변수
int PAUSE;        //게임의 일시정지 변수
int score;        //점수
int block[7][4][4][4] = { // T모양 블럭, 꺽인 블럭1, 꺽인 블럭2, 일자블럭, ㄴ자형 블럭 1, ㄴ자형 블럭 2, ㅁ자 블럭 순
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
};//블럭 들

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
};//기본 맵

bool Finishline(int x, int y) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[newblock][Rotation][i][j] == 1) {
				int t = map[i + y][j + x / 2];
				if (t == 1 || t == 2) { // 벽일 때, 블럭일 때
					return true;
				}
			}
		}
	}
	return false;
}  //블럭이 이동할 수 있는지 판단하는 함수(이동시 블럭이 충돌하지 않는지)

void hidecursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
} //커서를 숨기는 함수(외부에서 가져옴)
void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}//커서의 좌표를 이동시키는함수
void Randomblock() {
	srand(time(NULL));
	nextblock = rand() % 7;
}//블럭이 랜덤하게 나오도록 하는 함수
void DropBlock() {
	Dropend = clock();
	if (Dropend >= Dropstart + 800 - score / 1000) { //점수가 증가하면 떨어지는 속도도 증가
		if (Finishline(x, y + 1) == true) return;
		else {
			Dropstart = clock();
			Reachground = clock();
			system("cls");
			y++;
			k = 0;
		}
	}
}//시간이 지남에 따라 블럭이 낙하하도록 하는 함수
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
}//블럭이 바닥까지 갔을시 블럭을 낙하 상태에서 낙하가 끝난 블럭(벽)으로 바꾸기
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
}//한줄을 꽉채울시 줄을 지우면 추가 점수를 주는 함수
void DrawMap() {
	gotoxy(0, 4);
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 12; j++) {
			if (map[i][j] == 1) {
				gotoxy(j * 2, i);
				printf("▩");
			}
			else if (map[i][j] == 2) {
				gotoxy(j * 2, i);
				printf("□");
			}
		}
	}
}//현재 맵을 출력하는 함수
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
}//하드드롭을 하도록 하는 함수
void DrawBlock() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[newblock][Rotation][i][j] == 1) {
				gotoxy(x + j * 2, y + i);
				printf("■");
			}
		}
	}
}//현재 낙하중인 블럭을 출력하는 함수
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
	printf("테트리스를 플레이 해주셔서 감사합니다.");
	gotoxy(8, 9);
	printf("당신의 점수는 %d점입니다.", score);
	if (highscore >= score) {
		gotoxy(8, 10);
		printf("아쉽네요, 최고점수는 %s의 %d 점입니다.\n", highname, highscore);
		gotoxy(8, 11);
		printf("좀 더 노력해보세요.");
	}
	else if (highscore < score) {
		fclose(fp);
		gotoxy(8, 10);
		printf("축하합니다. 신기록이에요!\n");
		gotoxy(8, 11);
		printf("이니셜을 입력해주세요 : ");
		char initial[20];
		scanf("%s", initial);
		fp = fopen("highscore.txt", "w");
		if (!fp) {
			printf("Fail to open the file as the write mode.\n");
			return 0;
		}
		fprintf(fp, "%s %d", initial, score);
	}
	printf("TETRIS를 종료합니다.");
	fclose(fp);
}//게임이 끝났음을 인식하고 "hidhscore.txt" 파일에 저장된 최고기록과 비교하여 최고기록일시 이니셜을 남기도록 하는 함수

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

} // 키를 누를시 눌린 키를 인식하고 알맞은 행동을 하도록 하는 함수
int remote() {
	if (kbhit()) return getch();
	else return -1;
}//외부에서 가져온 함수 (방향키 등의 입력 및 제어)

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
}//처음 게임 시작시 메인메뉴에서 넘어가는 동안

void next1() {
	int k = nextblock;
	if (k == 0) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //글자색 변경 함수
		gotoxy(30, 6);
		printf("■");
		gotoxy(32, 6);
		printf("■");
		gotoxy(34, 6);
		printf("■");
		gotoxy(32, 5);
		printf("■");
	}
	else if (k == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		gotoxy(34, 5);
		printf("■");
		gotoxy(32, 5);
		printf("■");
		gotoxy(30, 6);
		printf("■");
		gotoxy(32, 6);
		printf("■");
	}
	else if (k == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		gotoxy(30, 5);
		printf("■");
		gotoxy(32, 5);
		printf("■");
		gotoxy(32, 6);
		printf("■");
		gotoxy(34, 6);
		printf("■");
	}
	else if (k == 3) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		gotoxy(30, 4);
		printf("■");
		gotoxy(30, 5);
		printf("■");
		gotoxy(30, 6);
		printf("■");
		gotoxy(30, 7);
		printf("■");
	}
	else if (k == 4) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		gotoxy(30, 5);
		printf("■");
		gotoxy(30, 6);
		printf("■");
		gotoxy(32, 6);
		printf("■");
		gotoxy(34, 6);
		printf("■");
	}
	else if (k == 5) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		gotoxy(30, 6);
		printf("■");
		gotoxy(32, 6);
		printf("■");
		gotoxy(34, 5);
		printf("■");
		gotoxy(34, 6);
		printf("■");
	}
	else if (k == 6) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		gotoxy(30, 5);
		printf("■");
		gotoxy(30, 6);
		printf("■");
		gotoxy(32, 5);
		printf("■");
		gotoxy(32, 6);
		printf("■");
	}
}//다음에 올 블럭 출력
void next() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	gotoxy(26, 1);
	printf("score : %d", score);
	gotoxy(26, 2);
	printf("    NEXT    ");
	gotoxy(26, 3);
	printf("■■■■■■");
	gotoxy(26, 4);
	printf("■        ■");
	gotoxy(26, 5);
	printf("■        ■");
	gotoxy(26, 6);
	printf("■        ■");
	gotoxy(26, 7);
	printf("■        ■");
	gotoxy(26, 8);
	printf("■■■■■■");
	next1();
}//NEXT 부분 출력
void menu() {
	gotoxy(1, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("       ■■■■■ ■■■■ ■■■■■  ■■■■  ■■■■   ■■■\n");
	gotoxy(1, 3);
	printf("           ■     ■           ■      ■    ■     ■     ■ \n");
	gotoxy(1, 4);
	printf("           ■     ■■■■     ■      ■■■       ■      ■■■\n");
	gotoxy(1, 5);
	printf("           ■     ■           ■      ■   ■      ■           ■\n");
	gotoxy(1, 6);
	printf("           ■     ■■■■     ■      ■    ■  ■■■■   ■■■ \n");
	gotoxy(1, 9);
	printf("Right : →");
	gotoxy(1, 10);
	printf("Left  : ←");
	gotoxy(1, 11);
	printf("Down  : ↓");
	gotoxy(1, 12);
	printf("Rotate: ↑");
	gotoxy(1, 13);
	printf("HardDrop: Space");
	gotoxy(1, 14);
	printf("Pause : Esc");
	gotoxy(17, 10);
	printf("TETRIS는 1307 마스터에 의해 만들어졌습니다.");
	gotoxy(17, 11);
	printf("현재 여러분이 플레이하고 계신 TETRIS의 저작권은 1307 마스터에게 있습니다.");
	gotoxy(17, 12);
	printf("그럼 모두 즐거운 TETRIS 하세요.");
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
}//조작키 설명 및 게임시작 전 대기하는 메뉴화면

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
				printf("재개하려면 Enter키를 눌러주세요");
				char u;
				scanf("%c", &u);
				rewind(stdin);//버퍼제거
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
}//메인 함수