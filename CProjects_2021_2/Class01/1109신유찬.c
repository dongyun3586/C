#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
void graph(int* num[100]);//그래프 그리기
void calculator(int Calcul[60][60], int Calcul2[60][60], int num2);// 행렬 계산기
void game();// 게임 창 출력
void gotoxy(int x, int y);//커서 위치 이동

void stat() {//게임판 출력
	for (int i = 20; i <= 70; i++) {
		for (int j = 5; j <= 20; j++) {
			if (i == 20 || i == 70 || j == 5 || j == 20) {
				gotoxy(i, j);
				printf("@");
			}
		}
	}
}

void start() {// 시작화면 출력
	printf("                                         ##                                              \n");

	printf("  #####    ####    ##        #####   ##  ##   ##        ####    ######    ####    #####   \n");

	printf(" ##  ##   ##  ##   ##       ##  ##   ##  ##   ##       ##  ##     ##     ##  ##   ##  ##  \n");


	printf(" ##       ######   ##       ##       ##  ##   ##       ######     ##     ##  ##   ##  ##  \n");


	printf(" ##       ##  ##   ##       ##       ##  ##   ##       ##  ##     ##     ##  ##   #####   \n");

	printf("  ######  ##  ##   ######    ######   ####    ######   ##  ##     ##      ####    ##  ##  \n");

	printf("              #                                            #       #                      \n");

}
int main() {
	int arr[100] = { 0, };// 그래프에 사용할 인자 저장
	int num[100] = { 0, };// 그래프에 사용할 인자를 함수에 넘김
	int n; // 여기까지 그래프 그리기
	int Calcul[60][60] = { 0, };// 행렬 1 입력
	int Calcul2[60][60] = { 0, };// 행렬 2 입력
	int num2 = 0;//정사각행렬의 크기

	while (1) { // 입력될 때까지 무한반복

		// 시작화면, 할 것 선택(1=그래프 그리기, 2=행렬 계산기 , 3=미니 게임)
		if (kbhit()) {

			char hi;
			hi = getch();
			switch (hi) {
			case '1':
				goto GRAPH;
				break;
			case '2':
				goto CALCUL;
				break;
			case '3':
				goto GAME;
			}

		}
		gotoxy(1, 1);
		start();
		gotoxy(1, 14);
		printf("실행을 원하시는 프로그램의 번호를 누르세요");
		gotoxy(1, 16);
		printf("1.그래프 그리기");
		gotoxy(1, 18);
		printf("2.행렬 계산하기");
		gotoxy(1, 20);
		printf("3.미니게임");





	}
GRAPH:// 1번을 눌렀을 때 개수와 인자 입력받고 graph함수 실행
	system("cls");
	printf("숫자의 개수를 입력해주세요\n");
	scanf("%d", &n);
	printf("숫자를 입력해 주세요 : ");
	printf("\n***각 숫자의 빈도가 50번을 넘지 않게 할 것***\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		num[arr[i] - 1]++;
	}
	graph(&num);
CALCUL://2번을 눌렀을 때 행렬의 크기와 행렬 2개를 입력받고 calculator함수 실행
	system("cls");
	printf("행렬의 크기를 입력해주세요\n");
	scanf("%d", &num2);
	system("cls");
	printf("첫 번째 행렬을 입력하세요\n");
	for (int i = 0; i < num2; i++) {
		for (int j = 0; j < num2; j++) {
			scanf("%d", &Calcul[i][j]);
		}
	}
	system("cls");
	printf("두 번째 행렬을 입력하세요\n");
	for (int i = 0; i < num2; i++) {
		for (int j = 0; j < num2; j++) {
			scanf("%d", &Calcul2[i][j]);
		}
	}
	calculator(Calcul, Calcul2, num2);
	return 0;

GAME://3번을 눌렀을 때 game 함수를 실행
	system("cls");
	game();
}

void gotoxy(int x, int y)//커서 위치 이동 함수

{

	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void graph(int* num[100]) {//graph를 그려주는 함수(gotoxy이용)
	while (1) {
		gotoxy(1, 1);
		for (int i = 0; i < 51; i++) {
			gotoxy(1, i);
			if (i == 0) {
				printf("Y");
			}
			else if (i % 2 == 0) {
				printf("%d", 50 - i);
			}
			else if (i == 50) {
				printf("원점");
			}
			else
				printf("|");
		}
		for (int j = 1; j < 205; j++) {
			gotoxy(j, 50);
			if (j == 1) {
				printf("-");
			}
			if (j == 204) {
				printf("X");
			}
			else if ((j - 1) % 2 == 0) {
				if ((j - 1) % 20 == 0) {
					printf("%d", ((j - 1) / 20) - 1);
				}
				else
					printf("%d", ((j - 1) / 20));
				gotoxy(j + 2, 51);
				printf("%d", ((j - 1) / 2) % 10);
				if (j == 203) {
					gotoxy(j, 52);
					printf("0");
				}
			}
			else
				printf("-");
		}
		for (int i = 0; i < 100; i++) {
			int k = *(num + i);
			gotoxy((2 * i) + 5, 50 - k);
			if (k == 0) {

			}
			else

				printf("#");

		}
		// 그래프 안내
		gotoxy(210, 0);
		printf("x=숫자  ,  y=빈도수(번)");
		gotoxy(210, 1);
		printf("#=(x,y)");
		system("cls");
	}
}

void calculator(int Calcul[60][60], int Calcul2[60][60], int num2) { // 계산 방법 입력받고 계산 실행
	system("cls");
	char howto;
	while (1) { // 계산 방법 선택
		rewind(stdin);
		printf("행렬의 계산 방법을 선택해주세요\n");
		printf("1.덧셈\n2.뺄셈\n3.곱셈\n");
		if (kbhit()) {
			howto = getch();
			break;
		}
		system("cls");
	}
	if (howto == '1') {//1눌렀을 때 덧셈 실행
		system("cls");
		for (int i = 0; i < num2; i++) {
			for (int j = 0; j < num2; j++) {
				int t = *(Calcul[i] + j);
				int k = *(Calcul2[i] + j);
				*(Calcul[i] + j) = k + t;
			}
		}
		for (int i = 0; i < num2; i++) {
			for (int j = 0; j < num2; j++) {
				printf("%d ", *(Calcul[i] + j));
			}
			printf("\n");
		}
	}
	if (howto == '2') {//2 눌렀을 때 뺄셈 실행
		system("cls");
		for (int i = 0; i < num2; i++) {
			for (int j = 0; j < num2; j++) {
				int t = *(Calcul[i] + j);
				int k = *(Calcul2[i] + j);
				*(Calcul[i] + j) = t - k;
			}
		}
		for (int i = 0; i < num2; i++) {
			for (int j = 0; j < num2; j++) {
				printf("%d ", *(Calcul[i] + j));
			}
			printf("\n");
		}
	}
	int gop[60][60] = { 0, }; // 곱셈한 결과 행렬 저장
	if (howto == '3') {//3 눌렀을 때 곱셈 실행

		int x;
		for (int i = 0; i < num2; i++)
		{
			for (int j = 0; j < num2; j++)
			{
				int x = 0;
				for (int k = 0; k < num2; k++)
				{
					x += Calcul[i][k] * Calcul2[k][j];
				}
				printf("%d ", x);
			}
			printf("\n");
		}
	}

}


void game() {//game을 실행
	int starttime = clock();//시작시간
	int init = clock();//시각

	int point = 0;
	char hi = 0;
	int x = 0, y = 0;
	int flag = 2;//방향(상하좌우)
	gotoxy(21, 6);
	srand(time(NULL));
	int a;
A://시작위치
	a = rand() % 100 + 1;
	if (a < 21 || a>69) {
		goto A;
	}
	int b;
B://시작위치
	b = rand() % 100 + 1;
	if (b < 6 || b>19) {
		goto B;
	}


	while (1) {// 캐릭터 움직이기
		if (x < 20 || x>70 || y < 5 || y>20) {//게임판 벗어나는 것 방지
			x = 21;
			y = 6;
		}

		if (x == a && y == b) {//아이템 먹었을 때 점수 올림
			point++;
			goto A;



		}

		if (point == 5) {//게임 끝낼 조건 -> 점수 5점
			system("cls");
			printf("%d초만에 성공하셨습니다!!!", (init / 1000) - (starttime / 1000));
			return 0;
		}
		gotoxy(0, 0);
		printf("점수 : %d점\n", point);
		printf("%d초\n", (init / 1000) - (starttime / 1000));
		gotoxy(a, b);
		printf("♡");
		system("cls");
		gotoxy(x, y);
		printf("●");
		stat();
		if (flag == 1) {//속도 조절
			if (clock() - init > 30) {
				x--;
				init = clock();
			}
		}
		if (flag == 2) {
			if (clock() - init > 30) {
				x++;
				init = clock();
			}
		}
		if (flag == 3) {
			if (clock() - init > 50) {
				y--;
				init = clock();
			}
		}
		if (flag == 4) {
			if (clock() - init > 50) {
				y++;
				init = clock();
			}
		}
		if (_kbhit()) {//방향 조절
			hi = _getch();
			switch (hi) {

			case 'a':
				flag = 1;
				break;

			case 'd':
				flag = 2;
				break;

			case 'w':
				flag = 3;
				break;

			case 's':
				flag = 4;
				break;

			case 'z':
				return 0;
			}



		}
	}

}

