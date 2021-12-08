#include <stdio.h>

char loard[3][3];
char p1 = 'o';
char p2 = 'x';
char winner;

void print(char(*board)[9]);
void check(char(*board)[9], char player, int m, int n);
void CHECK(char player);
void main() {
	printf("Ultimate Tic Tac Toe\n\n");
	char board[9][9];
	char player;
	int x, y;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			board[i][j] = ' ';
		}
	}
	for (int i = 0; i < 81; i++) {
		player = p1;
		if (i % 2 == 1)
			player = p2;
		if (i == 0)
			printf("Start ");
		printf("%c : ", player);
		scanf("%d %d", &y, &x);
		x--;
		y--;
		board[x][y] = player;
		print(board);
		int m = x / 3;
		int n = y / 3;
		check(board, player, m, n);
		CHECK(player);
		if (winner == ' ') {
			printf("Tie ");
			break;
		}
		else if (winner != '\0') {
			printf("Winer is %c ", winner);
			break;
		}
		else
			printf("Continue ");
	}
}

void print(char(*board)[9]) {
	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0)
			printf("----------------------\n");
		for (int j = 0; j < 9; j++) {
			if (j % 3 == 0)
				printf("|");
			printf("%c ", board[i][j]);
		}
		printf("|\n");
	}
	printf("----------------------\n");
}

void check(char(*board)[9], char player, int m, int n) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[3 * m + i][3 * n + j] != player)
				break;
			if (j == 2)
				loard[m][n] = player;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[3 * m + j][3 * n + i] != player)
				break;
			if (j == 2)
				loard[m][n] = player;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (board[3 * m + i][3 * n + i] != player)
			break;
		if (i == 2)
			loard[m][n] = player;
	}
	for (int i = 0; i < 3; i++) {
		if (board[3 * m + i][3 * n + 2 - i] != player)
			break;
		if (i == 2)
			loard[m][n] = player;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[3 * m + i][3 * n + j] == ' ')
				break;
			if (i == 2 && j == 2)
				loard[m][n] = ' ';
		}
	}
}

void CHECK(char player) {
	char Loard = player;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (loard[i][j] != Loard)
				break;
			if (j == 2)
				winner = Loard;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (loard[j][i] != Loard)
				break;
			if (j == 2)
				winner = Loard;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (loard[i][i] != Loard)
			break;
		if (i == 2)
			winner = Loard;
	}
	for (int i = 0; i < 3; i++) {
		if (loard[i][2 - i] != Loard)
			break;
		if (i == 2)
			winner = Loard;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (loard[i][j] == '\0')
				break;
			if (i == 2 && j == 2)
				winner = ' ';
		}
	}
}
