#include<stdio.h>
#include<stdlib.h>
#include<windows.h> // c ǥ�� ���̺귯�� �ƴ�
#include<time.h>
#include<math.h>
#include<conio.h>

#define X_MAX 118 // Ŀ���� X = 118���� �̵���
#define WALL_MAX 56 // ����� �迭�� ũ���̴�.
#define Y_MAX 40 // �迭�� Y��ǥ�� ũ���̴�.

enum { BALL = 1, BAR, WALL }; // BRICK�� 4 �̻��� ���̴�. ��, ����, ���� ���� �����Ͽ���.
#define HIDDEN 0 // Ŀ�� ����� ��


#pragma region getch() �����
#define ENTER 13 // ����
#define LARROW 97 // A
#define RARROW 100 // D
#pragma endregion

#pragma region ����ü ����
typedef struct {
	int x, y;
} point; // �� ����ü�� ����

typedef struct {
	point edge[4];
} _brick; // �� ����ü�� ����

typedef struct {
	point left, right;
} _bar; // ���� ����ü�� ����
#pragma endregion

void gotoXY(int x, int y) { // �� �ڵ�� ���ͳݿ��� ������ �ڵ��Դϴ� ��ó:https://topnanis.tistory.com/173
	COORD pos = { x, y }; // pos��� short�� 2���� ����ü ����
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // Ŀ���� �̵��ϴ� �Լ�
}

void setcolor(int color, int bgcolor) // �� �ڵ� ���� ���ͳݿ��� ������ �ڵ��Դϴ�. ��ó:https://topnanis.tistory.com/173
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color); // ���� ����� �����ϴ� �Լ�, �� ������ ��Ʈ ������ ���Ѵ�.
}

void CursorView(char show)  //�� �ڵ嵵 ���ͳݿ��� �����Ͽ����ϴ�. ��ó : https://coding-factory.tistory.com/691
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO consoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	consoleCursor.bVisible = show;
	consoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &consoleCursor); // Ŀ���� ���߰ų� �����ִ� ���� �۾��� �ϴ� �Լ�
}

void showTitle() { // Ÿ��Ʋ�� �����ִ� �Լ�
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
			if (title[y - 5][j]) printf("��");
			else printf("  ");
		}
	}; // brick�� 2���� �迭�� �����Ͽ� ���
	gotoXY(x, y + 2);
	printf("���� ������ ���Ͽ� ����â�� ��ü ȭ������ ������ּ���!\n");
	gotoXY(x, y + 3);
	printf("����Ű : A, D Ű");
	gotoXY(50, 25);
	printf("press Enter to start"); // Ŀ���� �̵��ϸ� �ȳ� ������ ����Ѵ�.

	char key;
	while (1) {
		key = _getch();
		if (key == ENTER) break; // ���͸� ������ ȭ���� �ʱ�ȭ��Ų��.
	}

	system("cls");
}

#pragma region ����� �Լ���
int stage(int i, int* life, long long int* score);// ������ �� ���带 ��ü������ �ٷ�� �Լ�
int resetStage(int brickRow, char(*blockArr)[X_MAX], point* ball, _bar* bar, _brick* brick); // �������� �����ϴ� �Լ�
void resetBrick(int cnt, int(*brickColumn)[30], _brick* brick, int row); // �������� ��ġ�� �����ϴ� �Լ�
void moveBall(point* ball, point* moveTo); // ���� �� ���� �����̴� �Լ�
int checkBall(point ball, point moveTo, _brick* brick, _bar* bar, char(*blockArr)[X_MAX], int cnt); // ���� �ֺ� ������ ���� ������ ���� ��� �� ��ü�� �Ǵ��ϴ� �Լ�
int checkBallPosition(point ball, char(*blockArr)[X_MAX]); // �̸� �������� ���� ��ġ�� ��� ��� ���� �ִ��� �˷��ִ� �Լ�
void removeBrick(_brick brick, char(*blockArr)[X_MAX]); // ������ ���� ����� �� ������ �����ϴ� �Լ�
int checkStageEnd(int* brickArr, int cnt); // ������ ���������� �������� Ȯ���ϴ� �Լ�
void setBricks(char(*blockArr)[X_MAX], _brick brick, int num); // blockArr�� ������ ��ġ�� ����ִ� �Լ�
void showStage(char(*blockArr)[X_MAX], point* ball, _bar* bar, _brick* brick); // �� ���� ���۽� ���� ó�� ���¸� �����ִ� �Լ�
void re_resetStage(char(*blockArr)[X_MAX], point* ball, _bar* bar, int* life); // ���� ������ life�� ���ҽ� �������� �����ϰ� �ٽ� �����ִ� �Լ�(���� ���� �ٲ��)
void moveBar(_bar* bar, char(*blockArr)[X_MAX], int move); // �Է¿� ���� ���븦 �̵���Ű�� �Լ�
#pragma endregion

int main() { // Ÿ��Ʋ�� �����ְ�, �ʱ� ���������� �����ϰ�, ������ �����Ѵ�.
	showTitle(); // Ÿ��Ʋ�� �����ش�

	srand(time(NULL));//�����Լ��� seed���� �����Ѵ�.

	int life = 4; // ������
	int level = 1; // ����
	long long int score = 0; //����,  ������� ���ӿ� ���� �⺻���� ������ �����Ѵ�.

	while (stage(level, &life, &score)) level++; // life�� ������ �ɶ����� ������ �����Ѵ�.
	gotoXY(10, 20);//���� ������ ������ Ŀ���� �̵��ϰ�
	printf("GAME OVER"); // ���ӿ����� ����Ѵ�.
	return 0; // ���α׷��� �����Ѵ�.
}

int stage(int level, int* life, long long int* score) { // �� ������ ��ü���� ����� ����ϴ� �Լ�
	char blockArr[Y_MAX][X_MAX] = { 0 }; // x 118�� 0, y 0�� ��������, ������-1���� ����(��ĭ�� ��)
	int speedCnt = level >= 12 ? 8 : 20 - level, cnt = 0; // speedCnt�� ��ŭ ƨ���� �� �������� ��, cnt: ���� ƨ�� Ƚ��
	int brickRow; // ���� �� ��

	//�� �κ��� ������ ���� ������ ���� ������ ���Ѵ�.
	if (level <= 10) brickRow = 4;
	else if (level > 10 && level <= 20) brickRow = 5;
	else  brickRow = 6;


	point ball, moveTo; // ��, ���� �̵��� ���� ����
	_bar bar; // �� �ĳ� ����
	_brick brick[90]; // ���� �迭��, �̷������� ������ �ִ� ������ ���� 14���� �۰�, 14* 6 + 4 = 88������ �ǹǷ� ����� ū ������ 90���� �Ҵ��Ͽ���.


	int blockCnt = resetStage(brickRow, blockArr, &ball, &bar, brick); //resetStage���� ��ȯ�� ���� ������ blockCnt�� �����Ѵ�.
	showStage(blockArr, &ball, &bar, brick); // �������� �����ش�.

	int brickArr[90] = { 0 }; // �� ������ ����������� ���θ� ������ �迭�̴�.
	for (int i = 4; i < blockCnt + 4; i++) brickArr[i] = 1; // ������ ������ �ش��ϴ� ���� 1�� �����Ѵ�.

	clock_t delay = 200; // �� �̵������� �����̸� 200ms�� �Ѵ�.
	// ���� �̵������� 1, 1�� �����Ѵ�.
	moveTo = (point){ 1, -1 };

	setcolor(15, 0);// ����� �ؽ�Ʈ�� ���� ������� �ٲ۴�.
	gotoXY(10, Y_MAX + 1);
	printf("score: %lld", *score);
	gotoXY(10, Y_MAX + 2);
	printf("life: %d", *life); // Ŀ���� blockArr�� �ش��ϴ� �κ� ������ ������ ������ ���� �������� ����Ѵ�.

	for (int i = 0; i < 15; i++)
		Sleep(delay); // 3�ʰ� ����Ѵ�.
	CursorView(HIDDEN); //Ŀ���� �Ⱥ��̰� �����Ѵ�. 

	int result; // checkBall�� �Լ��� ������ �����̴�.
	int key; // Ű������ �Է°��� �����Ѵ�.
	while (1) {
		if (cnt == speedCnt) {
			if (level <= 100) delay = 101 - level; // ���� Ƚ�� �̻� ƨ��� delay�� ���δ�.
			else delay = 0;
		}

		if (_kbhit()) {  //����Ű�� �ԷµǾ��� ��� ���븦 ������
			key = _getch(); // key�� �޴´�.
			if (key == RARROW) moveBar(&bar, blockArr, 2);
			else if (key == LARROW) moveBar(&bar, blockArr, -2); //key�� ���� ���븦 �̵��Ѵ�.
		}
		rewind(stdin);
		if (checkStageEnd(brickArr, blockCnt)) break; // ������ �� ���ٸ� �ش� ������ ������.
		// ���� �̵������� �� ������ �ִ��� Ȯ���ϴ� �Լ��� �����.
		switch (result = checkBall(ball, moveTo, brick, &bar, blockArr, blockCnt)) {
			// ���� �浹�ϴ� ���� ��찡 ���ٸ� -> ���� �̵���Ų��. ���� �̵����Ѱ��鼭 ����� �� ����� ����Ѵ�.
		case 0:
			gotoXY(ball.x * 2, ball.y);
			printf("��");
			blockArr[ball.y][ball.x] = 0;
			moveBall(&ball, &moveTo);
			gotoXY(ball.x * 2, ball.y);
			blockArr[ball.y][ball.x] = BALL;
			printf("��");
			Sleep(delay);
			break;
			// ���� ���� �浹�Ͽ��ٸ�, ���� �̵� ������ �ٲ۴�.
		case WALL:
			if (ball.y == Y_MAX - 2) { // ���� ���� �Ʒ��� ������ ���ٸ�, life�� ���ҽ�Ű��, ���� life�� ���� ���� ���ӿ��� �Ǵ� ���� �ʱ�ȭ�Ѵ�.
				(*life)--;
				cnt = 0;
				speedCnt = 4; // �߰������� ƨ�� Ƚ���� �����ϰ�, delay�� speedCnt�� �����Ѵ�.
				delay = 150;
				if (*life < 0) goto end;
				re_resetStage(blockArr, &ball, &bar, life);
				moveTo = (point){ 1, -1 };
			}
			else {
				if (ball.y == 1)moveTo.y *= -1; // õ���� ���, y �̵�����
				if (ball.x == 1 || ball.x == WALL_MAX - 2) moveTo.x *= -1; // �� ���� x������ �ٲ۴�.(�� �� ���ÿ� ����� ���� �ִ�)
				cnt++;
			}
			break;
			// ����� ƨ�� �͵� ���� ����ϳ�, ����� ���� ���θ� �������Ƿ� moveTo.y�� -1�� ���Ѵ�.
		case BAR:
			moveTo.y *= -1;
			if (ball.x == bar.left.x - 1)moveTo.x = -1;
			if (ball.x == bar.right.x + 1) moveTo.x = 1;
			cnt++;
			break;
			//������ ƨ�� ��� , ������ ���ְ� ������ ���Ѵ�.
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
		//��, ����, ������ ƨ�� ��� cnt�� ++�Ͽ� Ư�� ȸ�� �̻� ƨ�� �� delay�� ���δ�.
	}

end: // ���ӿ��� �� �̵��� ���̺��̴�.
	if (*life >= 0) return 1; // ����
	return 0; // ���ӿ���
}

int resetStage(int brickRow, char(*blockArr)[X_MAX], point* ball, _bar* bar, _brick* brick) {

	gotoXY(0, 0);//���� ������ �Ѿ �� Ŀ���� �̵��Ѵ�.
	//sum: ���� ���� ����
	//now: ���� ������ ũ�⸦ �Ҵ��� �� �̿��� x�� ��ǥ
	int sum = 0, now;
	int minus = 2; // minus: ������ �ϴ� ĭ(���������� ���� �����̴�)

	int brickColumn[10][30] = { 0 }; // ������ ū ũ���� �迭 ���� 
	//���� �Ҵ����� �Ź� �� ���, �����Ҵ��ϴ� �������� ũ�⵵ ���Ƿ�, ũ�� ���̰� ���� �ʴ´�.
	//����, �����Ҵ��� ��� �ټ� ���� �ɸ��� ������ �����ߴ�.

	//�� �κ��� ������ ��, ���� �����Ѵ�. �������� ���� ��ĭ�� ������ ����Ǿ���.
	for (int i = 0; i < brickRow; i++) {
		now = 0;
		for (int j = 0;; j++) {
			now += rand() % 3 + 4;
			brickColumn[i][j] = now;
			sum++;

			if (WALL_MAX - now - minus <= 6) { // ���� ĭ�� 6 ������ ���
				j++, now = WALL_MAX - minus;
				brickColumn[i][j] = now;
				sum++;
				break;
			}

			else if (6 < WALL_MAX - now - minus && WALL_MAX - now - minus < 12) { // ���� ĭ�� 7~12�� ���
				int rest = (WALL_MAX - now) / 2;
				now += rest, j++, sum++;
				brickColumn[i][j] = now;
				now = WALL_MAX - minus, j++, sum++;
				brickColumn[i][j] = now;
				break; // 7~12ĭ�� 2���� �ɰ��� ���� ��ǥ�� �ش�.
			} // ���⼭ brickColumn[i][j]�� i�� j��°�� ������ ������ �� ��ǥ�� �ǹ��Ѵ�.

		}
	}

	// �� brick���� �迭�� ���� ���� ������ ���� �ʺ����  �����Ѵ�.
	resetBrick(sum + 4, brickColumn, brick, brickRow);

	//ball, bar ��ġ�� �ʱ�ȭ�Ѵ�.
	bar->left = (point){ 27, Y_MAX - 3 }, bar->right = (point){ 34, Y_MAX - 3 }; // ����� �Ͽ����� ���� �ʾƼ� �ϵ��ڵ���
	*ball = (point){ 30, (Y_MAX / 2) + 10 };//���⵵ ���������̴�.


	// blockArr�� ������ ��� �־� �ʱ�ȭ���ѵд�.
	// blockArr�� ������, �������̹Ƿ� -> y��, x������ �����Ͽ��� �Ѵ�.
	blockArr[ball->y][ball->x] = BALL; // ���� ��ġ

	for (int i = bar->left.x; i <= bar->right.x; i++)
		blockArr[bar->left.y][i] = BAR;//������ ��ġ

	//���� ��ġ
	for (int i = 0; i < WALL_MAX; i++)
		blockArr[0][i] = blockArr[Y_MAX - 1][i] = WALL;
	for (int i = 0; i < Y_MAX; i++)
		blockArr[i][0] = blockArr[i][WALL_MAX - 1] = WALL;

	for (int i = 0; i < sum; i++)
		setBricks(blockArr, brick[i + 4], i + 4);//������ �ϳ��� �����Ѵ�.

	return sum;//���� ���� ��ȯ
}

void resetBrick(int cnt, int(*brickColumn)[30], _brick* brick, int row) {
	int brickNum = 4;
	for (int i = 0; i < row; i++) { // ������ ������ ��ǥ�� �ϳ��� ����
		for (int j = 0; brickColumn[i][j] != 0; j++) {

			if (j == 0) { // ���� ù ���̶�� ���� ��ǥ�� 1�� �����Ѵ�. ��������ǥ�� brickColumn�� i�� j���� �������Ѵ�.
				brick[brickNum].edge[0] = (point){ 1, i * 3 + 1 + 5 };
				brick[brickNum].edge[1] = (point){ brickColumn[i][j], i * 3 + 1 + 5 };
				brick[brickNum].edge[2] = (point){ brickColumn[i][j], (i + 1) * 3 + 5 }; // y��ǥ�� (3i + 1) + 5�� 3(i+1)+5���� �Ͽ���.
				brick[brickNum].edge[3] = (point){ 1, (i + 1) * 3 + 5 };
			}

			else { // ù���� �ƴ϶�� ���� ��ǥ�� ���� ������ ������ ��ǥ + 1�� �Ѵ�.
				brick[brickNum].edge[0] = (point){ brickColumn[i][j - 1] + 1, i * 3 + 1 + 5 };
				brick[brickNum].edge[1] = (point){ brickColumn[i][j], i * 3 + 1 + 5 };
				brick[brickNum].edge[2] = (point){ brickColumn[i][j], (i + 1) * 3 + 5 };
				brick[brickNum].edge[3] = (point){ brickColumn[i][j - 1] + 1, (i + 1) * 3 + 5 };
			}

			brickNum++; // ������ 4���� �����Ͽ� ���� ���� ������.(3�� ���̰�, �� ���ĺ��� ������ ���� ����.)
		}
	}
}

void setBricks(char(*blockArr)[X_MAX], _brick brick, int num) { // ������ ��ġ�� blockArr�� �ִ´�.
	for (int i = brick.edge[0].x; i <= brick.edge[1].x; i++) // for������ blockArr�� ������ ���� �ִ´�.
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


	int arr[90]; // ������ ������ ������ �迭��, ����� ũ�� �����Ѵ�.
	for (int i = 0; i < 90; i++)
		arr[i] = rand() % 6 + 9;

	for (int i = 0; i < Y_MAX; i++) { // �켱 ���� ���ܸ� ��� ����ϰ�
		for (int j = 0; j < WALL_MAX; j++) {
			if (blockArr[i][j] == WALL)
				printf("��");
			else if (blockArr[i][j] == BAR)
				printf("��");
			else if (blockArr[i][j] == BALL)
				printf("��");
			else
				printf("��");
		}
		printf("\n");
	}

	for (int i = 1; i < Y_MAX - 1; i++) { // ������ ������ �ٲ㰡�� ����Ѵ�.
		for (int j = 1; j < WALL_MAX - 1; j++) {
			gotoXY(2 * j, i);
			if ((tmp = blockArr[i][j]) > 3) {
				setcolor(arr[tmp], 0);
				printf("��");
			}
		}
	}


}

void re_resetStage(char(*blockArr)[X_MAX], point* ball, _bar* bar, int* life) { // �� �ڵ�� showStage, resetStage�� �ڵ带 �����Ͽ���.
	blockArr[ball->y][ball->x] = 0;
	for (int i = bar->left.x; i <= bar->right.x; i++)
		blockArr[bar->left.y][i] = 0;

	//ball, bar ��ġ�� �ʱ�ȭ�Ѵ�.
	bar->left = (point){ 27, Y_MAX - 3 }, bar->right = (point){ 34, Y_MAX - 3 }; // ����� �Ͽ����� ���� �ʾƼ� �ϵ��ڵ���
	*ball = (point){ 30, (Y_MAX / 2) + 10 };//���⵵ ���������̴�.

	// blockArr�� ������ ��� �־� �ʱ�ȭ���ѵд�.
	// blockArr�� ������, �������̹Ƿ� -> y��, x������ �����Ͽ��� �Ѵ�.
	blockArr[ball->y][ball->x] = BALL; // ���� ��ġ

	for (int i = bar->left.x; i <= bar->right.x; i++)
		blockArr[bar->left.y][i] = BAR;

	// �� �κ� ���� showStage��, �� �κ��� resetStage�� ���� ������, �ڵ带 �����Ͽ���.

	Sleep(250);
	gotoXY(0, 0);

	int arr[90];
	for (int i = 0; i < 90; i++)
		arr[i] = rand() % 6 + 9;

	for (int i = 0; i < Y_MAX; i++) {
		for (int j = 0; j < WALL_MAX; j++) {
			if (blockArr[i][j] == WALL)
				printf("��");
			else if (blockArr[i][j] == BAR)
				printf("��");
			else if (blockArr[i][j] == BALL)
				printf("��");
			else if (blockArr[i][j] == 0)
				printf("��");
			else {
				setcolor(arr[blockArr[i][j]], 0);
				printf("��");
				setcolor(15, 0);
			}
		}
		printf("\n");
	}

	gotoXY(10, Y_MAX + 2);
	printf("life: %d", *life);

	for (int i = 0; i < 12; i++)
		Sleep(250); // 3�ʰ� ���
}

void moveBall(point* ball, point* moveTo) { // ���� moveTo��ŭ �̵��Ѵ�.
	ball->x += moveTo->x;
	ball->y += moveTo->y;
}

int checkBall(point ball, point moveTo, _brick* brick, _bar* bar, char(*blockArr)[X_MAX], int cnt) {
	//���� 1,0  , 0,1   , 1,1 �������� �̵��ϸ� �ִ� ��Ͽ� ���� ����� �����Ѵ�.
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
	return blockArr[ball.y][ball.x]; // �ش� ��ġ�� ��ȣ�� ��ȯ�Ѵ�.
}

void removeBrick(_brick brick, char(*blockArr)[X_MAX]) { // ������ �����ϰ�, �ش� ��ġ�� ��ĭ�� ����Ѵ�. blockArr�� �ش� ���� 0���� �Ѵ�.
	for (int i = brick.edge[0].x; i <= brick.edge[2].x; i++)
		for (int j = brick.edge[0].y; j <= brick.edge[2].y; j++) {
			blockArr[j][i] = 0;
			gotoXY(i * 2, j);
			printf("��");
		}


}

int checkStageEnd(int* brickArr, int cnt) {
	for (int i = 4; i <= cnt + 4; i++) //brickArr�� 4���� ��� ���� �����Ͽ� ��� 0�̸� 1��, �ƴϸ� 0�� ��ȯ�Ѵ�.
		if (brickArr[i]) return 0;
	return 1;
}

void moveBar(_bar* bar, char(*blockArr)[X_MAX], int move) { // bar�� �̵��Ѵ�.
	if (bar->left.x == 1 && move == -2) return;
	if (bar->right.x == WALL_MAX - 2 && move == 2) return; // ������/���� ���̰� ������/�������� �̵��Ϸ� �� �� ��� �����Ѵ�.
	if (move > 0) { // ������
		bar->left.x += move;
		bar->right.x += move;
		int x = bar->left.x - 2, y = bar->left.y;
		gotoXY(2 * x, y);
		blockArr[y][x] = blockArr[y][x + 1] = 0;
		printf("����");
		x = bar->right.x - 1;
		gotoXY(2 * x, y);
		printf("���"), blockArr[y][x] = blockArr[y][x + 1] = BAR;
	}
	else { // ����
		bar->left.x += move;
		bar->right.x += move;
		int x = bar->left.x, y = bar->left.y;
		gotoXY(2 * x, y);
		blockArr[y][x] = blockArr[y][x + 1] = BAR;
		printf("���");
		x = bar->right.x + 1;
		gotoXY(2 * x, y);
		printf("����"), blockArr[y][x] = blockArr[y][x + 1] = 0;
	}
}