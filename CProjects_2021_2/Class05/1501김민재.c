#include<stdio.h>
#include<stdlib.h>
#include<windows.h> // c 표준 라이브러리 아님
#include<time.h>
#include<math.h>
#include<conio.h>

#define X_MAX 118 // 커서가 X = 118까지 이동됨
#define WALL_MAX 56 // 사용할 배열의 크기이다.
#define Y_MAX 40 // 배열의 Y좌표의 크기이다.

enum { BALL = 1, BAR, WALL }; // BRICK은 4 이상의 값이다. 공, 막대, 벽의 값을 설정하였다.
#define HIDDEN 0 // 커서 숨기는 값


#pragma region getch() 상수값
#define ENTER 13 // 엔터
#define LARROW 97 // A
#define RARROW 100 // D
#pragma endregion

#pragma region 구조체 정의
typedef struct {
	int x, y;
} point; // 점 구조체를 정의

typedef struct {
	point edge[4];
} _brick; // 벽 구조체를 정의

typedef struct {
	point left, right;
} _bar; // 막대 구조체를 정의
#pragma endregion

void gotoXY(int x, int y) { // 이 코드는 인터넷에서 참고한 코드입니다 출처:https://topnanis.tistory.com/173
	COORD pos = { x, y }; // pos라는 short형 2개의 구조체 선언
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // 커서를 이동하는 함수
}

void setcolor(int color, int bgcolor) // 이 코드 역시 인터넷에서 참조한 코드입니다. 출처:https://topnanis.tistory.com/173
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color); // 색과 배경을 지정하는 함수, 각 변수에 비트 연산을 취한다.
}

void CursorView(char show)  //이 코드도 인터넷에서 참고하였습니다. 출처 : https://coding-factory.tistory.com/691
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO consoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	consoleCursor.bVisible = show;
	consoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &consoleCursor); // 커서를 감추거나 보여주는 등의 작업을 하는 함수
}

void showTitle() { // 타이틀을 보여주는 함수
	char title[5][21] = {
		{1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1},
		{1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
		{1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0},
		{1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
		{1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1}
	};
	int x = 25, y = 5;
	for (y = 5; y < 10; y++) {
		gotoXY(x, y);
		for (int j = 0; j < 21; j++) {
			if (title[y - 5][j]) printf("■");
			else printf("  ");
		}
	}; // brick을 2차원 배열로 설정하여 출력
	gotoXY(x, y + 2);
	printf("게임 진행을 위하여 실행창을 전체 화면으로 만들어주세요!\n");
	gotoXY(x, y + 3);
	printf("조작키 : A, D 키");
	gotoXY(50, 25);
	printf("press Enter to start"); // 커서를 이동하며 안내 내용을 출력한다.

	char key;
	while (1) {
		key = _getch();
		if (key == ENTER) break; // 엔터를 받으면 화면을 초기화시킨다.
	}

	system("cls");
}

#pragma region 사용할 함수들
int stage(int i, int* life, long long int* score);// 게임의 한 라운드를 전체적으로 다루는 함수
int resetStage(int brickRow, char(*blockArr)[X_MAX], point* ball, _bar* bar, _brick* brick); // 게임판을 리셋하는 함수
void resetBrick(int cnt, int(*brickColumn)[30], _brick* brick, int row); // 벽돌들의 위치를 지정하는 함수
void moveBall(point* ball, point* moveTo); // 게임 중 공을 움직이는 함수
int checkBall(point ball, point moveTo, _brick* brick, _bar* bar, char(*blockArr)[X_MAX], int cnt); // 공의 주변 지형에 따라 다음에 공이 닿게 될 물체를 판단하는 함수
int checkBallPosition(point ball, char(*blockArr)[X_MAX]); // 미리 움직여본 공의 위치가 어느 블록 위에 있는지 알려주는 함수
void removeBrick(_brick brick, char(*blockArr)[X_MAX]); // 벽돌이 공과 닿았을 때 벽돌을 제거하는 함수
int checkStageEnd(int* brickArr, int cnt); // 게임이 성공적으로 끝났는지 확인하는 함수
void setBricks(char(*blockArr)[X_MAX], _brick brick, int num); // blockArr에 벽돌의 위치를 집어넣는 함수
void showStage(char(*blockArr)[X_MAX], point* ball, _bar* bar, _brick* brick); // 각 레벨 시작시 판의 처음 상태를 보여주는 함수
void re_resetStage(char(*blockArr)[X_MAX], point* ball, _bar* bar, int* life); // 공이 떨어져 life가 감소시 게임판을 리셋하고 다시 보여주는 함수(벽돌 색은 바뀐다)
void moveBar(_bar* bar, char(*blockArr)[X_MAX], int move); // 입력에 따라 막대를 이동시키는 함수
#pragma endregion

int main() { // 타이틀을 보여주고, 초기 변수값들을 설정하고, 게임을 실행한다.
	showTitle(); // 타이틀을 보여준다

	srand(time(NULL));//랜덤함수의 seed값을 리셋한다.

	int life = 4; // 라이프
	int level = 1; // 레벨
	long long int score = 0; //점수,  여기까지 게임에 사용될 기본적인 값들을 세팅한다.

	while (stage(level, &life, &score)) level++; // life가 음수가 될때까지 게임을 진행한다.
	gotoXY(10, 20);//만약 게임이 끝나면 커서를 이동하고
	printf("GAME OVER"); // 게임오버를 출력한다.
	return 0; // 프로그램을 종료한다.
}

int stage(int level, int* life, long long int* score) { // 한 레벨의 전체적인 기능을 담당하는 함수
	char blockArr[Y_MAX][X_MAX] = { 0 }; // x 118과 0, y 0과 마지막줄, 마지막-1줄은 못씀(빈칸과 벽)
	int speedCnt = level >= 12 ? 8 : 20 - level, cnt = 0; // speedCnt번 만큼 튕겼을 때 빨라지게 함, cnt: 현재 튕긴 횟수
	int brickRow; // 벽돌 열 수

	//이 부분은 레벨에 따라서 벽돌의 행의 개수를 정한다.
	if (level <= 10) brickRow = 4;
	else if (level > 10 && level <= 20) brickRow = 5;
	else  brickRow = 6;


	point ball, moveTo; // 공, 공이 이동할 방향 설정
	_bar bar; // 공 쳐낼 막대
	_brick brick[90]; // 벽돌 배열로, 이론적으로 가능한 최대 벽돌의 수는 14보다 작고, 14* 6 + 4 = 88정도가 되므로 충분히 큰 숫자인 90개를 할당하였다.


	int blockCnt = resetStage(brickRow, blockArr, &ball, &bar, brick); //resetStage에서 반환한 벽돌 개수를 blockCnt에 저장한다.
	showStage(blockArr, &ball, &bar, brick); // 게임판을 보여준다.

	int brickArr[90] = { 0 }; // 각 벽돌이 사라졌는지의 여부를 저장할 배열이다.
	for (int i = 4; i < blockCnt + 4; i++) brickArr[i] = 1; // 생성된 벽돌에 해당하는 값을 1로 설정한다.

	clock_t delay = 200; // 각 이동마다의 딜레이를 200ms로 한다.
	// 공의 이동방향을 1, 1로 선언한다.
	moveTo = (point){ 1, -1 };

	setcolor(15, 0);// 출력할 텍스트의 색을 흰색으로 바꾼다.
	gotoXY(10, Y_MAX + 1);
	printf("score: %lld", *score);
	gotoXY(10, Y_MAX + 2);
	printf("life: %d", *life); // 커서를 blockArr에 해당하는 부분 밖으로 보내어 점수와 남은 라이프를 출력한다.

	for (int i = 0; i < 15; i++)
		Sleep(delay); // 3초간 대기한다.
	CursorView(HIDDEN); //커서를 안보이게 설정한다. 

	int result; // checkBall의 함수를 저장할 변수이다.
	int key; // 키보드의 입력값을 저장한다.
	while (1) {
		if (cnt == speedCnt) {
			if (level <= 100) delay = 101 - level; // 일정 횟수 이상 튕길시 delay를 줄인다.
			else delay = 0;
		}

		if (_kbhit()) {  //방향키가 입력되었을 경우 막대를 움직임
			key = _getch(); // key를 받는다.
			if (key == RARROW) moveBar(&bar, blockArr, 2);
			else if (key == LARROW) moveBar(&bar, blockArr, -2); //key에 따라 막대를 이동한다.
		}
		rewind(stdin);
		if (checkStageEnd(brickArr, blockCnt)) break; // 벽돌이 다 없다면 해당 레벨을 끝낸다.
		// 공을 이동시켰을 때 무엇이 있는지 확인하는 함수를 만든다.
		switch (result = checkBall(ball, moveTo, brick, &bar, blockArr, blockCnt)) {
			// 만약 충돌하는 공의 경우가 없다면 -> 공을 이동시킨다. 공을 이동시켜가면서 공백과 공 모양을 출력한다.
		case 0:
			gotoXY(ball.x * 2, ball.y);
			printf("　");
			blockArr[ball.y][ball.x] = 0;
			moveBall(&ball, &moveTo);
			gotoXY(ball.x * 2, ball.y);
			blockArr[ball.y][ball.x] = BALL;
			printf("●");
			Sleep(delay);
			break;
			// 만약 벽과 충돌하였다면, 공의 이동 방향을 바꾼다.
		case WALL:
			if (ball.y == Y_MAX - 2) { // 만약 공이 아래쪽 벽으로 갔다면, life를 감소시키고, 남은 life에 값에 따라 게임오버 또는 맵을 초기화한다.
				(*life)--;
				cnt = 0;
				speedCnt = 4; // 추가적으로 튕긴 횟수를 리셋하고, delay와 speedCnt를 조절한다.
				delay = 150;
				if (*life < 0) goto end;
				re_resetStage(blockArr, &ball, &bar, life);
				moveTo = (point){ 1, -1 };
			}
			else {
				if (ball.y == 1)moveTo.y *= -1; // 천장의 경우, y 이동방향
				if (ball.x == 1 || ball.x == WALL_MAX - 2) moveTo.x *= -1; // 양 옆은 x방향을 바꾼다.(둘 다 동시에 실행될 수도 있다)
				cnt++;
			}
			break;
			// 막대와 튕긴 것도 벽과 비슷하나, 막대는 공이 위로만 지나가므로 moveTo.y는 -1만 곱한다.
		case BAR:
			moveTo.y *= -1;
			if (ball.x == bar.left.x - 1)moveTo.x = -1;
			if (ball.x == bar.right.x + 1) moveTo.x = 1;
			cnt++;
			break;
			//벽돌에 튕길 경우 , 벽돌을 없애고 점수를 더한다.
		default:
			brickArr[result] = 0;
			if (ball.x == brick[result].edge[0].x - 1 || ball.x == brick[result].edge[1].x + 1) moveTo.x *= -1;
			if (ball.y == brick[result].edge[0].y - 1 || ball.y == brick[result].edge[2].y + 1) moveTo.y *= -1;
			removeBrick(brick[result], blockArr);

			*score += rand() % 2 + 4;
			gotoXY(10, Y_MAX + 1);
			printf("score: %lld", *score);
			cnt++;
			break;

		}
		//벽, 막대, 벽돌에 튕길 경우 cnt를 ++하여 특정 회수 이상 튕길 시 delay를 줄인다.
	}

end: // 게임오버 시 이동할 레이블이다.
	if (*life >= 0) return 1; // 성공
	return 0; // 게임오버
}

int resetStage(int brickRow, char(*blockArr)[X_MAX], point* ball, _bar* bar, _brick* brick) {

	gotoXY(0, 0);//다음 레벨로 넘어갈 시 커서를 이동한다.
	//sum: 벽돌 수의 총합
	//now: 이후 벽돌의 크기를 할당할 때 이용할 x축 좌표
	int sum = 0, now;
	int minus = 2; // minus: 빠져야 하는 칸(시행착오를 위한 변수이다)

	int brickColumn[10][30] = { 0 }; // 적당히 큰 크기의 배열 선언 
	//동적 할당으로 매번 할 경우, 동적할당하는 포인터의 크기도 들어가므로, 크게 차이가 나지 않는다.
	//또한, 동적할당의 경우 다소 렉이 걸리는 현상이 존재했다.

	//이 부분은 벽돌의 행, 렬을 지정한다. 나머지에 따라 빈칸이 없도록 설계되었다.
	for (int i = 0; i < brickRow; i++) {
		now = 0;
		for (int j = 0;; j++) {
			now += rand() % 3 + 4;
			brickColumn[i][j] = now;
			sum++;

			if (WALL_MAX - now - minus <= 6) { // 남은 칸이 6 이하인 경우
				j++, now = WALL_MAX - minus;
				brickColumn[i][j] = now;
				sum++;
				break;
			}

			else if (6 < WALL_MAX - now - minus && WALL_MAX - now - minus < 12) { // 남은 칸이 7~12인 경우
				int rest = (WALL_MAX - now) / 2;
				now += rest, j++, sum++;
				brickColumn[i][j] = now;
				now = WALL_MAX - minus, j++, sum++;
				brickColumn[i][j] = now;
				break; // 7~12칸을 2개로 쪼개어 각각 좌표를 준다.
			} // 여기서 brickColumn[i][j]는 i행 j번째의 벽돌의 오른쪽 끝 좌표를 의미한다.

		}
	}

	// 각 brick마다 배열을 만들어서 임의 지정된 벽돌 너비들을  결정한다.
	resetBrick(sum + 4, brickColumn, brick, brickRow);

	//ball, bar 위치를 초기화한다.
	bar->left = (point){ 27, Y_MAX - 3 }, bar->right = (point){ 34, Y_MAX - 3 }; // 상수로 하였으나 되지 않아서 하드코딩함
	*ball = (point){ 30, (Y_MAX / 2) + 10 };//여기도 마찬가지이다.


	// blockArr에 값들을 모두 넣어 초기화시켜둔다.
	// blockArr는 세로축, 가로축이므로 -> y축, x축으로 생각하여야 한다.
	blockArr[ball->y][ball->x] = BALL; // 공의 위치

	for (int i = bar->left.x; i <= bar->right.x; i++)
		blockArr[bar->left.y][i] = BAR;//막대의 위치

	//벽의 위치
	for (int i = 0; i < WALL_MAX; i++)
		blockArr[0][i] = blockArr[Y_MAX - 1][i] = WALL;
	for (int i = 0; i < Y_MAX; i++)
		blockArr[i][0] = blockArr[i][WALL_MAX - 1] = WALL;

	for (int i = 0; i < sum; i++)
		setBricks(blockArr, brick[i + 4], i + 4);//벽돌을 하나씩 대입한다.

	return sum;//벽돌 개수 반환
}

void resetBrick(int cnt, int(*brickColumn)[30], _brick* brick, int row) {
	int brickNum = 4;
	for (int i = 0; i < row; i++) { // 벽돌의 꼭짓점 좌표를 하나씩 지정
		for (int j = 0; brickColumn[i][j] != 0; j++) {

			if (j == 0) { // 만약 첫 열이라면 왼쪽 좌표를 1로 지정한다. 오른쪽좌표는 brickColumn의 i행 j열의 값으로한다.
				brick[brickNum].edge[0] = (point){ 1, i * 3 + 1 + 5 };
				brick[brickNum].edge[1] = (point){ brickColumn[i][j], i * 3 + 1 + 5 };
				brick[brickNum].edge[2] = (point){ brickColumn[i][j], (i + 1) * 3 + 5 }; // y좌표는 (3i + 1) + 5와 3(i+1)+5으로 하였다.
				brick[brickNum].edge[3] = (point){ 1, (i + 1) * 3 + 5 };
			}

			else { // 첫열이 아니라면 왼쪽 좌표를 이전 벽돌의 오른쪽 좌표 + 1로 한다.
				brick[brickNum].edge[0] = (point){ brickColumn[i][j - 1] + 1, i * 3 + 1 + 5 };
				brick[brickNum].edge[1] = (point){ brickColumn[i][j], i * 3 + 1 + 5 };
				brick[brickNum].edge[2] = (point){ brickColumn[i][j], (i + 1) * 3 + 5 };
				brick[brickNum].edge[3] = (point){ brickColumn[i][j - 1] + 1, (i + 1) * 3 + 5 };
			}

			brickNum++; // 벽돌을 4부터 지정하여 점점 더해 나간다.(3은 벽이고, 그 이후부터 벽돌의 값이 들어간다.)
		}
	}
}

void setBricks(char(*blockArr)[X_MAX], _brick brick, int num) { // 벽돌의 위치를 blockArr에 넣는다.
	for (int i = brick.edge[0].x; i <= brick.edge[1].x; i++) // for문으로 blockArr에 벽돌의 값을 넣는다.
		blockArr[brick.edge[0].y][i] = num;
	for (int i = brick.edge[1].y; i <= brick.edge[2].y; i++)
		blockArr[i][brick.edge[1].x] = num;
	for (int i = brick.edge[3].x; i <= brick.edge[2].x; i++)
		blockArr[brick.edge[3].y][i] = num;
	for (int i = brick.edge[0].y; i <= brick.edge[3].y; i++)
		blockArr[i][brick.edge[0].x] = num;
}

void showStage(char(*blockArr)[X_MAX], point* ball, _bar* bar, _brick* brick) {
	int tmp;


	int arr[90]; // 벽돌의 색상을 지정할 배열로, 충분히 크게 지정한다.
	for (int i = 0; i < 90; i++)
		arr[i] = rand() % 6 + 9;

	for (int i = 0; i < Y_MAX; i++) { // 우선 벽돌 제외를 모두 출력하고
		for (int j = 0; j < WALL_MAX; j++) {
			if (blockArr[i][j] == WALL)
				printf("□");
			else if (blockArr[i][j] == BAR)
				printf("■");
			else if (blockArr[i][j] == BALL)
				printf("●");
			else
				printf("　");
		}
		printf("\n");
	}

	for (int i = 1; i < Y_MAX - 1; i++) { // 벽돌을 색상을 바꿔가며 출력한다.
		for (int j = 1; j < WALL_MAX - 1; j++) {
			gotoXY(2 * j, i);
			if ((tmp = blockArr[i][j]) > 3) {
				setcolor(arr[tmp], 0);
				printf("■");
			}
		}
	}


}

void re_resetStage(char(*blockArr)[X_MAX], point* ball, _bar* bar, int* life) { // 이 코드는 showStage, resetStage의 코드를 재사용하였다.
	blockArr[ball->y][ball->x] = 0;
	for (int i = bar->left.x; i <= bar->right.x; i++)
		blockArr[bar->left.y][i] = 0;

	//ball, bar 위치를 초기화한다.
	bar->left = (point){ 27, Y_MAX - 3 }, bar->right = (point){ 34, Y_MAX - 3 }; // 상수로 하였으나 되지 않아서 하드코딩함
	*ball = (point){ 30, (Y_MAX / 2) + 10 };//여기도 마찬가지이다.

	// blockArr에 값들을 모두 넣어 초기화시켜둔다.
	// blockArr는 세로축, 가로축이므로 -> y축, x축으로 생각하여야 한다.
	blockArr[ball->y][ball->x] = BALL; // 공의 위치

	for (int i = bar->left.x; i <= bar->right.x; i++)
		blockArr[bar->left.y][i] = BAR;

	// 이 부분 밑은 showStage와, 위 부분은 resetStage와 같은 원리로, 코드를 재사용하였다.

	Sleep(250);
	gotoXY(0, 0);

	int arr[90];
	for (int i = 0; i < 90; i++)
		arr[i] = rand() % 6 + 9;

	for (int i = 0; i < Y_MAX; i++) {
		for (int j = 0; j < WALL_MAX; j++) {
			if (blockArr[i][j] == WALL)
				printf("□");
			else if (blockArr[i][j] == BAR)
				printf("■");
			else if (blockArr[i][j] == BALL)
				printf("●");
			else if (blockArr[i][j] == 0)
				printf("　");
			else {
				setcolor(arr[blockArr[i][j]], 0);
				printf("■");
				setcolor(15, 0);
			}
		}
		printf("\n");
	}

	gotoXY(10, Y_MAX + 2);
	printf("life: %d", *life);

	for (int i = 0; i < 12; i++)
		Sleep(250); // 3초간 대기
}

void moveBall(point* ball, point* moveTo) { // 공울 moveTo만큼 이동한다.
	ball->x += moveTo->x;
	ball->y += moveTo->y;
}

int checkBall(point ball, point moveTo, _brick* brick, _bar* bar, char(*blockArr)[X_MAX], int cnt) {
	//공을 1,0  , 0,1   , 1,1 방향으로 이동하며 있는 블록에 따라 결과를 리턴한다.
	int result;

	ball.x += moveTo.x;
	if (result = checkBallPosition(ball, blockArr)) return result;
	ball.x -= moveTo.x;
	ball.y += moveTo.y;
	if (result = checkBallPosition(ball, blockArr)) return result;
	ball.x += moveTo.x;
	if (result = checkBallPosition(ball, blockArr)) return result;


	return 0;
}

int checkBallPosition(point ball, char(*blockArr)[X_MAX]) {
	return blockArr[ball.y][ball.x]; // 해당 위치의 번호를 반환한다.
}

void removeBrick(_brick brick, char(*blockArr)[X_MAX]) { // 벽돌을 제거하고, 해당 위치에 빈칸을 출력한다. blockArr의 해당 값을 0으로 한다.
	for (int i = brick.edge[0].x; i <= brick.edge[2].x; i++)
		for (int j = brick.edge[0].y; j <= brick.edge[2].y; j++) {
			blockArr[j][i] = 0;
			gotoXY(i * 2, j);
			printf("　");
		}


}

int checkStageEnd(int* brickArr, int cnt) {
	for (int i = 4; i <= cnt + 4; i++) //brickArr의 4부터 모든 항을 조사하여 모두 0이면 1을, 아니면 0을 반환한다.
		if (brickArr[i]) return 0;
	return 1;
}

void moveBar(_bar* bar, char(*blockArr)[X_MAX], int move) { // bar를 이동한다.
	if (bar->left.x == 1 && move == -2) return;
	if (bar->right.x == WALL_MAX - 2 && move == 2) return; // 오른쪽/왼쪽 끝이고 오른쪽/왼쪽으로 이동하려 할 때 즉시 리턴한다.
	if (move > 0) { // 오른쪽
		bar->left.x += move;
		bar->right.x += move;
		int x = bar->left.x - 2, y = bar->left.y;
		gotoXY(2 * x, y);
		blockArr[y][x] = blockArr[y][x + 1] = 0;
		printf("　　");
		x = bar->right.x - 1;
		gotoXY(2 * x, y);
		printf("■■"), blockArr[y][x] = blockArr[y][x + 1] = BAR;
	}
	else { // 왼쪽
		bar->left.x += move;
		bar->right.x += move;
		int x = bar->left.x, y = bar->left.y;
		gotoXY(2 * x, y);
		blockArr[y][x] = blockArr[y][x + 1] = BAR;
		printf("■■");
		x = bar->right.x + 1;
		gotoXY(2 * x, y);
		printf("　　"), blockArr[y][x] = blockArr[y][x + 1] = 0;
	}
}