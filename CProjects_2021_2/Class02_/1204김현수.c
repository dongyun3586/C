#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>


#define LEFT 97 //a
#define RIGHT 100 //d
#define UP 119 // w
#define DOWN 115 // s
int score = 0; // ����
int act; // ���� ��ȭ ������ �˷��ִ� ����
int board[4][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
void start(void);
void makeboard(void);// ������ ������ �������� ����� �Լ��Դϴ�.
void newnum(void);// ���ο� ���ڸ� �߰����� �Լ��Դϴ�.
int gameover(void);// ���� �������� üũ���ִ� �Լ��Դϴ�.
int gameclear(void); // ������ Ŭ�����ߴ��� üũ���ִ� �Լ��Դϴ�
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
	newnum(); // ���� �ΰ� ���� ����
	newnum();
	makeboard();
	while (1) {
		key = getch();

		switch (key) {
		case LEFT:
			left();// ���ʹ������� ����
			break;

		case RIGHT:
			right();// ������
			break;

		case UP:
			up();// ����
			break;

		case DOWN:
			down(); // �Ʒ���
			break;
		default: act = 0;
			break;

		}

		boardclear(); // �����Ҷ� ������ 10000 ������
		if (act > 0)
			afteract(); // ������ ������

	}
}

void makeboard(void) {
	int i, j;
	system("cls");// �ܼ�â�� ������
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (board[i][j] == 0)
				printf("    ."); // 0�� ���忡  ǥ�õ��� �����Ƿ� ������ �ٲ��ش�
			else
				printf("%5d", board[i][j]);

		}
		printf("\n");
	}
	printf("\n");
	printf("����: %d \n", score); // ���� ������ ǥ�����ش�
}
void newnum(void) {
	int i, j;
	int x;
	int* pointer[16] = { 0 };

	for (i = 0, x = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 0) {
				pointer[x] = &board[i][j]; // ���ڰ� �����ϴ� ���� �ּҵ��� �����Ϳ� �����Ѵ�. �̸� �̿��� ��������� ���ڰ� �����ǵ��� �Ѵ�. 
				x++;
			}
		}
	}
	*pointer[rand() % x] = (rand() % 100 < 70) ? 2 : 4; // �̴� 70%Ȯ���� 2�� �����ǰ� 30% Ȯ���� 4�� �����ȴ�.
}
int gameover(void) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 0)
				return 0;// 0�� �ϳ��� ������ ���ӿ����� �ƴϴ�.
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == board[i + 1][j] || board[i][j] == board[i][j + 1])
				return 0; // ���� ���� ���ڰ� ������ ��ĥ �� �־ ���ӿ��� �ƴϴ�.
		}
	}
	for (int i = 0; i < 3; i++) {
		if (board[i][3] == board[i + 1][3])
			return 0;
	}
	for (int j = 0; j < 3; j++)
		if (board[3][j] == board[3][j + 1])
			return 0;
	printf("���ӿ���"); // �� ���ؿ� ���յǴ°�찡 �ƿ� ������ ���ӿ����̴�.
	return 1;
}
int gameclear(void) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] >= 2048) {
				printf("�����մϴ�. ������ Ŭ���� �߽��ϴ�!!"); // ���� 2048�� �ϳ��� ����� �Ǹ� ������ Ŭ���� �Ѱ��̴�.
				return 1;
			}
		}
	}
	return 0;
}
void left(void) { // �������� �����϶� �������� ��� ������ �������� �Լ��̴�
	int hit = 0;
	int i, j, k;
	for (i = 0, act = 0; i < 4; i++) { // ��
		for (int j = 1; j <= 3; j++) { // �� �����̹Ƿ� ù���� ����
			for (int k = j; k > 0; k--) {
				if (board[i][k] == 0 || board[i][k] > 10000) // �ڱ� ��ġ�� ���� 0�ϰ�쿡�� �����
					break;
				if (board[i][k - 1] != 0 && board[i][k] != board[i][k - 1]) // �ڱ� ���� ���� �ڱ� ���� �ٸ��� �ٲ��� �����Ƿ� �ٲ��� �ʴ´�(��, 0�϶��� �ƴϹǷ� 0�ΰ�� ����)
					break;
				if (board[i][k - 1] == 0)
					board[i][k - 1] = board[i][k]; // ���� ���� 0�̴ϱ� �ڱⰪ �״�� ����
				else if (board[i][k - 1] == board[i][k]) {
					board[i][k - 1] *= 2;// �ڱⰪ �ι����� ex) 22->40
					board[i][k - 1] += 10000; // �̴� 2222�� 8000�� �Ǵ°� �ƴ϶� 4400�� �ǵ��� �Ϸ��� ������̴�. �Ϲ����� ��쿡�� 10000�� ������ �ռ� ���ǿ� ���� ���߰� �ȴ�.
					score += 2 * (board[i][k]); // ������ �÷��ش�
				}
				board[i][k] = 0; // �ڱⰪ�� ������ �Ű����� 0���� �ٲ۴�
				act++;//�׼��� ������ �˸���.
			}
		}
	}
}
void right(void) {
	int hit = 0;
	int i, j, k;
	for (i = 0, act = 0; i < 4; i++) { // ��
		for (int j = 2; j >= 0; j--) { // �� �������̹Ƿ� ������ ����
			for (int k = j; k < 3; k++) {
				if (board[i][k] == 0 || board[i][k] > 10000) // �ڱ� ��ġ�� ���� 0�ϰ�쿡�� �����
					break;
				if (board[i][k + 1] != 0 && board[i][k] != board[i][k + 1]) // �ڱ� �����ʰ��� �ڱ� ���� �ٸ��� �ٲ��� �����Ƿ� �ٲ��� �ʴ´�(��, 0�϶��� �ƴϹǷ� 0�ΰ�� ����)
					break;
				if (board[i][k + 1] == 0)
					board[i][k + 1] = board[i][k]; // ������ ���� 0�̴ϱ� �ڱⰪ �״�� ����
				else if (board[i][k + 1] == board[i][k]) {
					board[i][k + 1] *= 2;// �ڱⰪ �ι����� ex) 22->40
					board[i][k + 1] += 10000; // �̴� 2222�� 8000�� �Ǵ°� �ƴ϶� 4400�� �ǵ��� �Ϸ��� ������̴�. �Ϲ����� ��쿡�� 10000�� ������ �ռ� ���ǿ� ���� ���߰� �ȴ�.
					score += 2 * (board[i][k]); // ������ �÷��ش�
				}
				board[i][k] = 0; // �ڱⰪ�� ������ �Ű����� 0���� �ٲ۴�
				act++;//�׼��� ������ �˸���.
			}
		}
	}
}
void up(void) {
	int hit = 0;
	int i, k, j;
	for (j = 0, act = 0; j < 4; j++) { // ��
		for (int i = 1; i <= 3; i++) { // �� ù��°�� ����
			for (int k = i; k > 0; k--) {
				if (board[k][j] == 0 || board[k][j] > 10000) // �ڱ� ��ġ�� ���� 0�ϰ�쿡�� �����
					break;
				if (board[k - 1][j] != 0 && board[k - 1][j] != board[k][j]) // �ڱ� ���� ���� ���� �ٸ��� �ٲ��� �����Ƿ� �ٲ��� �ʴ´�(��, 0�϶��� �ƴϹǷ� 0�ΰ�� ����)
					break;
				if (board[k - 1][j] == 0)
					board[k - 1][j] = board[k][j]; // ���� ���� 0�̴ϱ� �ڱⰪ �״�� ����
				else if (board[k - 1][j] == board[k][j]) {
					board[k - 1][j] *= 2;// �ڱⰪ �ι����� ex) 22->40
					board[k - 1][j] += 10000; // �̴� 2222�� 8000�� �Ǵ°� �ƴ϶� 4400�� �ǵ��� �Ϸ��� ������̴�. �Ϲ����� ��쿡�� 10000�� ������ �ռ� ���ǿ� ���� ���߰� �ȴ�.
					score += 2 * (board[k][j]); // ������ �÷��ش�
				}
				board[k][j] = 0; // �ڱⰪ�� ������ �Ű����� 0���� �ٲ۴�
				act++;//�׼��� ������ �˸���.
			}
		}
	}

}
void down(void) {
	int hit = 0;
	int i, j, k;
	for (j = 0, act = 0; j < 4; j++) { // ��
		for (int i = 2; i >= 0; i--) { // �� �������� ����
			for (int k = i; k < 3; k++) {
				if (board[k][j] == 0 || board[k][j] > 10000) // �ڱ� ��ġ�� ���� 0�ϰ�쿡�� �����
					break;
				if (board[k + 1][j] != 0 && board[k + 1][j] != board[k][j]) // �ڱ� ���� �Ʒ��� ���� �ٸ��� �ٲ��� �����Ƿ� �ٲ��� �ʴ´�(��, 0�϶��� �ƴϹǷ� 0�ΰ�� ����)
					break;
				if (board[k + 1][j] == 0)
					board[k + 1][j] = board[k][j]; // �Ʒ��� ���� 0�̴ϱ� �ڱⰪ �״�� ����
				else if (board[k + 1][j] == board[k][j]) {
					board[k + 1][j] *= 2;// �ڱⰪ �ι����� ex) 22->40
					board[k + 1][j] += 10000; // �̴� 2222�� 8000�� �Ǵ°� �ƴ϶� 4400�� �ǵ��� �Ϸ��� ������̴�. �Ϲ����� ��쿡�� 10000�� ������ �ռ� ���ǿ� ���� ���߰� �ȴ�.
					score += 2 * (board[k][j]); // ������ �÷��ش�
				}
				board[k][j] = 0; // �ڱⰪ�� ������ �Ű����� 0���� �ٲ۴�
				act++;//�׼��� ������ �˸���.
			}
		}
	}
}

void boardclear(void) {
	for (int i = 0; i < 4; i++) { //��
		for (int j = 0; j < 4; j++) { //��
			if (board[i][j] > 10000)
				board[i][j] -= 10000;// ���߾��� 10000�� ����
		}
	}
}

void afteract(void) {
	newnum(); // ������ ������ ���ο� ���� �ϳ��� �߰��Ѵ�
	makeboard(); // �迭�� �ִ� ���� �������� �ֿܼ� ���带 �����.
	if (gameover()) {
		exit(0);
	}
	if (gameclear()) {
		exit(0);
	}

}