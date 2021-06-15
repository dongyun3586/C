#include <stdio.h>
#include <string.h>
void Print(int Arr[][4][4]);
int Scan(int Arr[][4][4], char Name1[], char Name2[], int Turn);
int Determine(int Arr[][4][4], int Det);
int Tie(int Arr[][4][4], int Blank, int Det);
int main() {
	int Arr[5][5][5] = { 0 };	// Arr[층][x][y]
	char Name1[100] = { 'c' }, Name2[100] = { 'c' };
	int Det = 0, Turn = 1, a, b, c, Blank = 0;				// Det -> 0이면 승부 안남, -1이면 무승부, 1이면 플레이어 1 승리, 2이면 플레이어 2 승리, Turn -> 1이면 플레이어 1, 2이면 플레이어 2, a, b, c는 각각 입력받는 높이, 가로, 세로, Blank를 통해 무승부 났는지 확인 -> 1이면 비어있음, 0이면 다 참
	printf("1514 최현민의 3차원 틱택토에 오신 것을 환영합니다!\n");
	printf("3차원 틱택토의 룰은 일반 틱택토와 비슷하게 가로, 세로, 높이, 대각선 중 한 줄을 먼저 만들어내는 플레이어가 이기게 됩니다.\n");
	printf("먼저 돌을 놓는 사람의 돌은 O로, 나중에 놓는 사람의 돌은 X로 표시됩니다.\n");
	printf("돌을 놓기 위해서는 (놓을 자리의 층), (놓을 자리의 x좌표), (놓을 자리의 y좌표)를 입력하세요.\n");
	printf("=======================================================================================================================\n");
	printf("플레이어 1의 이름: ");
	gets(Name1);						// 이 코드에서는 플레이어 1이 사용할 이름을 입력받습니다.
	printf("플레이어 2의 이름: ");
	gets(Name2);						// 이 코드에서는 플레이어 1이 사용할 이름을 입력받습니다.
	while (Det == 0) {
		Print(Arr);						// 이 함수에서는 게임이 진행되는 상황을 출력해줍니다.
		if (Turn == 1)
			printf("%s", Name1);
		else if (Turn == 2)
			printf("%s", Name2);
		Scan(Arr, Name1, Name2, Turn);							// Scan 끝줄
		Det = Determine(Arr, Det);						// 이 함수에서는 승부가 났는지를 판별해줍니다.
		Det = Tie(Arr, Blank, Det);						// 이 함수에서는 게임이 무승부인지를 판별해줍니다.
	}
	Print(Arr);
	if (Det == 1)
		printf("%s의 승리입니다!\n", Name1);
	else if (Det == 2)
		printf("%s의 승리입니다!\n", Name2);
	else if (Det == -1)
		printf("무승부입니다.\n");
	return 0;
}
void Print(int Arr[][4][4]) {
	for (int i = 1; i <= 4; i++) {
		for (int k = 1; k <= 4; k++) {
			if (k == 2)
				printf("%d층", i);
			printf("\t");
			for (int j = 1; j <= 4; j++) {
				if (Arr[i][j][k] == 0)
					printf("_ ");
				else if (Arr[i][j][k] == 1) {
					printf("O ");
				}
				else if (Arr[i][j][k] == 2) {
					printf("X ");
				}
			}
			printf("\n");
		}
		printf("\n\n\n");
	}
}
int Scan(int Arr[][4][4], char Name1[], char Name2[], int Turn) {
	int a, b, c;
	if (Turn == 1)
		printf("%s", Name1);
	else if (Turn == 2)
		printf("%s", Name2);
	printf("의 차례: ");			// Scan 첫줄
	scanf("%d %d %d", &a, &b, &c);
	while ((a < 1 || a > 4) || (b < 1 || b > 4) || (c < 1 || c > 4) || Arr[a][b][c] != 0) {
		printf("돌을 놓고 싶은 위치를 다시 입력해주세요!\n");
		if (Turn == 1)
			printf("%s", Name1);
		else if (Turn == 2)
			printf("%s", Name2);
		printf("의 차례: ");
		scanf("%d %d %d", &a, &b, &c);
	}
	Arr[a][b][c] = Turn;
	printf("\n");
	Turn = 3 - Turn;
	return Turn;
}
int Determine(int Arr[][4][4], int Det) {
	if (Arr[1][1][1] == Arr[2][2][2] && Arr[2][2][2] == Arr[3][3][3] && Arr[3][3][3] == Arr[4][4][4]) {					// Determine (공간대각선) 첫줄
		if (Arr[2][2][2] == 1)
			Det = 1;
		else if (Arr[2][2][2] == 2)
			Det = 2;
	}
	else if (Arr[1][4][1] == Arr[2][3][2] && Arr[2][3][2] == Arr[3][2][3] && Arr[3][2][3] == Arr[4][1][4]) {
		if (Arr[2][3][2] == 1)
			Det = 1;
		else if (Arr[2][3][2] == 2)
			Det = 2;
	}
	else if (Arr[1][1][4] == Arr[2][2][3] && Arr[2][2][3] == Arr[3][3][2] && Arr[3][3][2] == Arr[4][4][1]) {
		if (Arr[2][2][3] == 1)
			Det = 1;
		else if (Arr[2][2][3] == 2)
			Det = 2;
	}
	else if (Arr[1][4][4] == Arr[2][3][3] && Arr[2][3][3] == Arr[3][2][2] && Arr[3][2][2] == Arr[4][1][1]) {
		if (Arr[2][3][3] == 1)
			Det = 1;
		else if (Arr[2][3][3] == 2)
			Det = 2;
	}																			// Determine (공간대각선) 끝줄
	for (int i = 1; i <= 4; i++) {
		if (Arr[i][1][1] == Arr[i][2][2] && Arr[i][2][2] == Arr[i][3][3] && Arr[i][3][3] == Arr[i][4][4]) {		// Determine (면대각선) 첫줄
			if (Arr[i][2][2] == 1)
				Det = 1;
			else if (Arr[i][2][2] == 2)
				Det = 2;
		}
		if (Arr[i][1][4] == Arr[i][2][3] && Arr[i][2][3] == Arr[i][3][2] && Arr[i][3][2] == Arr[i][4][1]) {
			if (Arr[i][2][3] == 1)
				Det = 1;
			else if (Arr[i][2][3] == 2)
				Det = 2;
		}
		if (Arr[1][i][1] == Arr[2][i][2] && Arr[2][i][2] == Arr[3][i][3] && Arr[3][i][3] == Arr[4][i][4]) {
			if (Arr[2][i][2] == 1)
				Det = 1;
			else if (Arr[2][i][2] == 2)
				Det = 2;
		}
		if (Arr[1][i][4] == Arr[2][i][3] && Arr[2][i][3] == Arr[3][i][2] && Arr[3][i][2] == Arr[4][i][1]) {
			if (Arr[2][i][3] == 1)
				Det = 1;
			else if (Arr[2][i][3] == 2)
				Det = 2;
		}
		if (Arr[1][1][i] == Arr[2][2][i] && Arr[2][2][i] == Arr[3][3][i] && Arr[3][3][i] == Arr[4][4][i]) {
			if (Arr[2][2][i] == 1)
				Det = 1;
			else if (Arr[2][2][i] == 2)
				Det = 2;
		}
		if (Arr[1][4][i] == Arr[2][3][i] && Arr[2][3][i] == Arr[3][2][i] && Arr[3][2][i] == Arr[4][1][i]) {
			if (Arr[2][3][i] == 1)
				Det = 1;
			else if (Arr[2][3][i] == 2)
				Det = 2;
		}
	}																					// Determine (면대각선) 끝줄
	for (int i = 1; i <= 4; i++) {														// Determine (면직선) 첫줄
		for (int j = 1; j <= 4; j++) {
			if (Arr[i][j][1] == Arr[i][j][2] && Arr[i][j][2] == Arr[i][j][3] && Arr[i][j][3] == Arr[i][j][4]) {
				if (Arr[i][j][2] == 1)
					Det = 1;
				else if (Arr[i][j][2] == 2)
					Det = 2;
			}
			else if (Arr[i][1][j] == Arr[i][2][j] && Arr[i][2][j] == Arr[i][3][j] && Arr[i][3][j] == Arr[i][4][j]) {
				if (Arr[i][2][j] == 1)
					Det = 1;
				else if (Arr[i][2][j] == 2)
					Det = 2;
			}
			else if (Arr[1][i][j] == Arr[2][i][j] && Arr[2][i][j] == Arr[3][i][j] && Arr[3][i][j] == Arr[4][i][j]) {
				if (Arr[2][i][j] == 1)
					Det = 1;
				else if (Arr[2][i][j] == 2)
					Det = 2;
			}
		}
	}																				// Determine (면직선) 끝줄
	return Det;
}
int Tie(int Arr[][4][4], int Blank, int Det) {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				if (Arr[i][j][k] == 0) {
					Blank = 1;
					break;
				}
			}
		}
	}
	if (Blank == 0 && Det == 0) {
		Det = -1;
	}
	return Det;
}