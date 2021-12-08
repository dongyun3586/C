#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>


#define LEFT 97 //a
#define RIGHT 100 //d
#define UP 119 // w
#define DOWN 115 // s
int score = 0; // 점수
int act; // 판의 변화 유무를 알려주는 변수
int board[4][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
void start(void);
void makeboard(void);// 게임을 진행할 보드판을 만드는 함수입니다.
void newnum(void);// 새로운 숫자를 추가해줄 함수입니다.
int gameover(void);// 게임 오버인지 체크해주는 함수입니다.
int gameclear(void); // 게임을 클리어했는지 체크해주는 함수입니다
void left(void);
void right(void);
void up(void);
void down(void);
void boardclear(void);
void afteract(void);

int main() {
	start();

}
void start(void) {
	int key;
	newnum(); // 숫자 두개 랜덤 생성
	newnum();
	makeboard();
	while (1) {
		key = getch();

		switch (key) {
		case LEFT:
			left();// 왼쪽방향으로 실행
			break;

		case RIGHT:
			right();// 오른쪽
			break;

		case UP:
			up();// 위쪽
			break;

		case DOWN:
			down(); // 아래쪽
			break;
		default: act = 0;
			break;

		}

		boardclear(); // 실행할때 더해준 10000 없애줌
		if (act > 0)
			afteract(); // 실행이 됬을때

	}
}

void makeboard(void) {
	int i, j;
	system("cls");// 콘솔창을 지워줌
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (board[i][j] == 0)
				printf("    ."); // 0은 보드에  표시되지 않으므로 점으로 바꿔준다
			else
				printf("%5d", board[i][j]);

		}
		printf("\n");
	}
	printf("\n");
	printf("점수: %d \n", score); // 현재 점수를 표시해준다
}
void newnum(void) {
	int i, j;
	int x;
	int* pointer[16] = { 0 };

	for (i = 0, x = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 0) {
				pointer[x] = &board[i][j]; // 숫자가 존재하는 곳의 주소들을 포인터에 저장한다. 이를 이용해 빈곳에서만 숫자가 생성되도록 한다. 
				x++;
			}
		}
	}
	*pointer[rand() % x] = (rand() % 100 < 70) ? 2 : 4; // 이는 70%확률로 2가 생성되고 30% 확률로 4가 생성된다.
}
int gameover(void) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 0)
				return 0;// 0이 하나라도 있으면 게임오버가 아니다.
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == board[i + 1][j] || board[i][j] == board[i][j + 1])
				return 0; // 옆에 같은 숫자가 있으면 합칠 수 있어서 게임오버 아니다.
		}
	}
	for (int i = 0; i < 3; i++) {
		if (board[i][3] == board[i + 1][3])
			return 0;
	}
	for (int j = 0; j < 3; j++)
		if (board[3][j] == board[3][j + 1])
			return 0;
	printf("게임오버"); // 저 기준에 부합되는경우가 아예 없으면 게임오버이다.
	return 1;
}
int gameclear(void) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] >= 2048) {
				printf("축하합니다. 게임을 클리어 했습니다!!"); // 만약 2048을 하나라도 만들게 되면 게임을 클리어 한것이다.
				return 1;
			}
		}
	}
	return 0;
}
void left(void) { // 왼쪽으로 움직일때 보드판이 어떻게 변할지 시행해줄 함수이다
	int hit = 0;
	int i, j, k;
	for (i = 0, act = 0; i < 4; i++) { // 행
		for (int j = 1; j <= 3; j++) { // 열 왼쪽이므로 첫번쨰 제외
			for (int k = j; k > 0; k--) {
				if (board[i][k] == 0 || board[i][k] > 10000) // 자기 위치의 값이 0일경우에는 멈춘다
					break;
				if (board[i][k - 1] != 0 && board[i][k] != board[i][k - 1]) // 자기 왼쪽 값과 자기 값이 다르면 바뀌지 않으므로 바뀌지 않는다(단, 0일때는 아니므로 0인경우 제외)
					break;
				if (board[i][k - 1] == 0)
					board[i][k - 1] = board[i][k]; // 왼쪽 값이 0이니까 자기값 그대로 복사
				else if (board[i][k - 1] == board[i][k]) {
					board[i][k - 1] *= 2;// 자기값 두배해줌 ex) 22->40
					board[i][k - 1] += 10000; // 이는 2222가 8000이 되는게 아니라 4400이 되도록 하려고 만든것이다. 일반적인 경우에는 10000이 넘으면 앞서 조건에 의해 멈추게 된다.
					score += 2 * (board[i][k]); // 점수를 올려준다
				}
				board[i][k] = 0; // 자기값은 옆으로 옮겼으니 0으로 바꾼다
				act++;//액션이 있음을 알린다.
			}
		}
	}
}
void right(void) {
	int hit = 0;
	int i, j, k;
	for (i = 0, act = 0; i < 4; i++) { // 행
		for (int j = 2; j >= 0; j--) { // 열 오른쪽이므로 마지막 제외
			for (int k = j; k < 3; k++) {
				if (board[i][k] == 0 || board[i][k] > 10000) // 자기 위치의 값이 0일경우에는 멈춘다
					break;
				if (board[i][k + 1] != 0 && board[i][k] != board[i][k + 1]) // 자기 오른쪽값과 자기 값이 다르면 바뀌지 않으므로 바뀌지 않는다(단, 0일때는 아니므로 0인경우 제외)
					break;
				if (board[i][k + 1] == 0)
					board[i][k + 1] = board[i][k]; // 오른쪽 값이 0이니까 자기값 그대로 복사
				else if (board[i][k + 1] == board[i][k]) {
					board[i][k + 1] *= 2;// 자기값 두배해줌 ex) 22->40
					board[i][k + 1] += 10000; // 이는 2222가 8000이 되는게 아니라 4400이 되도록 하려고 만든것이다. 일반적인 경우에는 10000이 넘으면 앞서 조건에 의해 멈추게 된다.
					score += 2 * (board[i][k]); // 점수를 올려준다
				}
				board[i][k] = 0; // 자기값은 옆으로 옮겼으니 0으로 바꾼다
				act++;//액션이 있음을 알린다.
			}
		}
	}
}
void up(void) {
	int hit = 0;
	int i, k, j;
	for (j = 0, act = 0; j < 4; j++) { // 열
		for (int i = 1; i <= 3; i++) { // 행 첫번째는 제외
			for (int k = i; k > 0; k--) {
				if (board[k][j] == 0 || board[k][j] > 10000) // 자기 위치의 값이 0일경우에는 멈춘다
					break;
				if (board[k - 1][j] != 0 && board[k - 1][j] != board[k][j]) // 자기 값과 위쪽 값이 다르면 바뀌지 않으므로 바뀌지 않는다(단, 0일때는 아니므로 0인경우 제외)
					break;
				if (board[k - 1][j] == 0)
					board[k - 1][j] = board[k][j]; // 위쪽 값이 0이니까 자기값 그대로 복사
				else if (board[k - 1][j] == board[k][j]) {
					board[k - 1][j] *= 2;// 자기값 두배해줌 ex) 22->40
					board[k - 1][j] += 10000; // 이는 2222가 8000이 되는게 아니라 4400이 되도록 하려고 만든것이다. 일반적인 경우에는 10000이 넘으면 앞서 조건에 의해 멈추게 된다.
					score += 2 * (board[k][j]); // 점수를 올려준다
				}
				board[k][j] = 0; // 자기값은 위으로 옮겼으니 0으로 바꾼다
				act++;//액션이 있음을 알린다.
			}
		}
	}

}
void down(void) {
	int hit = 0;
	int i, j, k;
	for (j = 0, act = 0; j < 4; j++) { // 열
		for (int i = 2; i >= 0; i--) { // 행 마지막은 제외
			for (int k = i; k < 3; k++) {
				if (board[k][j] == 0 || board[k][j] > 10000) // 자기 위치의 값이 0일경우에는 멈춘다
					break;
				if (board[k + 1][j] != 0 && board[k + 1][j] != board[k][j]) // 자기 값과 아래쪽 값이 다르면 바뀌지 않으므로 바뀌지 않는다(단, 0일때는 아니므로 0인경우 제외)
					break;
				if (board[k + 1][j] == 0)
					board[k + 1][j] = board[k][j]; // 아래쪽 값이 0이니까 자기값 그대로 복사
				else if (board[k + 1][j] == board[k][j]) {
					board[k + 1][j] *= 2;// 자기값 두배해줌 ex) 22->40
					board[k + 1][j] += 10000; // 이는 2222가 8000이 되는게 아니라 4400이 되도록 하려고 만든것이다. 일반적인 경우에는 10000이 넘으면 앞서 조건에 의해 멈추게 된다.
					score += 2 * (board[k][j]); // 점수를 올려준다
				}
				board[k][j] = 0; // 자기값은 밑으로 옮겼으니 0으로 바꾼다
				act++;//액션이 있음을 알린다.
			}
		}
	}
}

void boardclear(void) {
	for (int i = 0; i < 4; i++) { //행
		for (int j = 0; j < 4; j++) { //열
			if (board[i][j] > 10000)
				board[i][j] -= 10000;// 더했었던 10000을 감소
		}
	}
}

void afteract(void) {
	newnum(); // 시행이 됬으면 새로운 숫자 하나를 추가한다
	makeboard(); // 배열에 있는 값을 바탕으로 콘솔에 보드를 만든다.
	if (gameover()) {
		exit(0);
	}
	if (gameclear()) {
		exit(0);
	}

}