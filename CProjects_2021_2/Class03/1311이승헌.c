#include <stdio.h>
#include <windows.h>
#include <time.h>

enum Difficulty { EASY = 1, NORMAL, HARD, EXPERT, END };//난이도 설정을 위한 열거체
int arr[9][9][2] = { 0 };                             //스도쿠가 들어갈 배열 arr[9][9][0], 스도쿠 0 판별을 위해 arr[9][9][1] 생성
int mistake = 0, game = 0;                              //mistake 게임 중 실수한 횟수, game 승리한 게임 횟수

void BasicArray();                                    //기본적인 스도쿠 배열 설정
void ExchangeRow();                                   //행끼리 교환
void ExchangeColumn();                                //열끼리 교환
void ExchangeNum();                                   //숫자끼리 자리 교환
void PrintArray();                                    //스도쿠 문제 출력
void AddBlank(int n);                                 //기본적인 스도쿠 배열에 0 추가(플레이하는 사람이 채울 칸)

int main() {


	int d, x, y, n, num = 0;                             //d : 난이도 설정을 위해 scanf에서 받는 변수, x, y : 입력받는 점의 좌표, num : 0으로 바꾸는 숫자의 개수
	int numArr[9][9] = { 0 };                          //arr 초기화
	enum Difficulty difficulty;                        //난이도를 각각 EASY=1, NORMAL=2, HARD=3, EXPERT=4로 설정하기 위한 열거체

start:                                                 //마지막의 goto문에서 돌아와서 게임 다시 시작

	srand(time(NULL));                                 //랜덤 수를 얻기 위한 srand(time(NULL))
	BasicArray(0);                                     //기본적인 배열 설정
	for (int i = 0; i < 15; i++) {
		ExchangeRow(0);                                //행, 열, 숫자끼리 자리를 교환해 배열을 변형
		ExchangeColumn(0);
		ExchangeNum(0);
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			numArr[i][j] = arr[i][j][0];              //arr에 있는 숫자들을 numArr에 저장
		}
	}

	printf("**************스도쿠**************\n");
	printf("\n   난이도를 선택하세요.\n   1.쉬움\n   2.보통\n   3.어려움\n   4.전문가\n   5.종료\n\n 난이도 : ");
	scanf("%d", &d);                                  //난이도 입력받기
	difficulty = d;                                   //난이도를 열거체를 이용해 switch case문에서 num 값 랜덤 지정
	switch (difficulty) {                             //5번을 고를 경우 게임 종료
	case EASY:
		num = rand() % 8 + 5;
		break;
	case NORMAL:
		num = rand() % 8 + 13;
		break;
	case HARD: num = rand() % 8 + 21;
		break;
	case EXPERT: num = rand() % 8 + 29;
		break;
	case END:
		return 0;
	}

	AddBlank(num);                                     //AddBlank 0추가 함수(0의 역할 : 사용자가 채워넣어야 하는 숫자 칸)
	system("cls");                                     //스도쿠나 난이도 출력되어 있는 화면 청소
	printf("\n\n\n\n\n     스도쿠 문제 생성 중 ......");
	Sleep(1000);
	system("cls");
	PrintArray(0);                                     //완성된 스도쿠 문제 출력

	while (1) {
		printf("\n\n좌표 x, y, 숫자 입력 (단, 가장 왼쪽 윗부분의 좌표=(1, 1)) : ");
		scanf("%d %d %d", &x, &y, &n);                 //좌표 입력받은 후 그 좌표에 대해 채울 숫자 입력
		if (arr[y - 1][x - 1][0] == 0) {               //해당 좌표에 있는 값이 0인지 아닌지 판별
			if (n == numArr[y - 1][x - 1]) {           //해당 좌표에 있는 값이 입력한 값과 일치하는지 판별
				arr[y - 1][x - 1][0] = n;              //일치할 경우 arr에 값 대입 후 num에서 1차감
				num--;
			}
			else {
				printf("\n틀렸습니다. ");              //해당 좌표에 있는 값과 일치하지 않을 경우
				mistake++;                             //실수 횟수 1회 추가
				Sleep(500);
			}
		}
		else {
			printf("\n해당 좌표의 값이 0이 아닙니다. ");//해당 좌표의 값이 0이 아닐 경우
			Sleep(500);
		}
		system("cls");                                  //화면 청소
		PrintArray(0);                                  //바뀐 배열 출력
		if (num == 0) {
			goto END;                                   //num이 0이 됐을 경우 반복문 종료 goto
		}
	}
END:
	system("cls");                                      //게임 승리
	printf("\n\n\n\n\n            축하합니다!!!");
	Sleep(2000);                                        //일정 시간 대기
	game++;                                             //승리한 게임 횟수 1회 추가
	system("cls");
	goto start;                                         //게임 다시 시작
}

void BasicArray() {
	for (int i = 0; i < 9; i++) {
		arr[0][i][0] = i + 1;                           //첫 줄을 1 2 3 4 5 6 7 8 9로 채운다.
	}
	for (int i = 1; i < 9; i++) {                       //나머지 숫자들이 스도쿠 규칙을 만족하도록 채운다
		for (int j = 0; j < 9; j++) {
			arr[i][j][0] = (arr[0][j][0] + 3 * i + i / 3) % 9;
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j][0] == 0) arr[i][j][0] = 9;
		}
	}
}

void PrintArray() {
	printf("\n\n  ");
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {                    //arr 출력
			printf(" %d ", arr[i][j][0]);
		}

		printf("\n  ");
	}
	printf("\n실수 : %d회\n승리한 게임 : %d번", mistake, game);//실수한 횟수, 승리한 게임 수 출력
}

void ExchangeRow() {
	int temp;
	srand(time(NULL));
	int a = rand() % 9;                                   //a번째 행과 b번째 행 교환
	int b = (a / 3) * 3;
	if (a == b) return 0;                                 //a=b일 때에는 종료
	else {
		for (int i = 0; i < 9; i++) {
			temp = arr[a][i][0];
			arr[a][i][0] = arr[b][i][0];
			arr[b][i][0] = temp;
		}
	}
}

void ExchangeColumn() {
	int temp;
	srand(time(NULL));
	int a = rand() % 9;                                   //a번째 열과 b번째 열 교환
	int b = (a / 3) * 3;
	if (a == b)return 0;
	else {
		for (int i = 0; i < 9; i++) {
			temp = arr[i][a][0];
			arr[i][a][0] = arr[i][b][0];
			arr[i][b][0] = temp;
		}
	}
}

void ExchangeNum() {
	int temp, a, b;
	srand(time(NULL));
	while (1) {
		a = rand() % 9;                                  //a, b를 1~9사이 중 랜덤하게 설정
		b = rand() % 9;
		if (a != b) break;
	}
	int k[2];                                            //a와 b값을 임시로 저장할 k[2] 설정
	int flag;                                            //동일한 행에서 본 적 있는지 판별을 위해 flag 선언
	for (int i = 0; i < 9; i++) {
		flag = 0;
		for (int j = 0; j < 9; j++) {
			if ((arr[i][j][0] == a || arr[i][j][0] == b) && flag == 0) {
				k[0] = arr[i][j][0];                     //flag=0 일 경우 = a나 b 값을 가진 좌표를 동일 행에서 처음 본 경우
				k[1] = j;                                //k[0]에 값 저장 후 k[1]에 좌표 저장
				flag++;                                  //flag = 1로 만들어 다른 a나 b 값을 가진 좌표를 발견했을 때 판별
			}
			else if ((arr[i][j][0] == a || arr[i][j][0] == b) && flag == 1) {
				arr[i][k[1]][0] = arr[i][j][0];          //flag=1일 경우 2번째로 발견
				arr[i][j][0] = k[0];                     //a와 b의 값을 교환
			}
		}
	}
}

void AddBlank(int n) {
	int number = 0;
	while (number != n) {
		int a = rand() % 9;
		int b = rand() % 9;
		if (arr[a][b][1] == 0) {                           //arr[a][b][1]이 0일 경우 arr[a][b][0]이 0이 아닌 수
			arr[a][b][0] = 0;                              //arr[a][b][0]을 0으로 변경하고 arr[a][b][1]을 1로 바꿔서 arr[a][b][0]이 0인 것을 표시한다.
			arr[a][b][1] = 1;
			number++;                                      //반복문을 n번까지 반복
		}
	}
}