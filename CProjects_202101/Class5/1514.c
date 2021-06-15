#include <stdio.h>
#include <string.h>
void Print(int Arr[][4][4]);
int Scan(int Arr[][4][4], char Name1[], char Name2[], int Turn);
int Determine(int Arr[][4][4], int Det);
int Tie(int Arr[][4][4], int Blank, int Det);
int main() {
	int Arr[5][5][5] = { 0 };	// Arr[��][x][y]
	char Name1[100] = { 'c' }, Name2[100] = { 'c' };
	int Det = 0, Turn = 1, a, b, c, Blank = 0;				// Det -> 0�̸� �º� �ȳ�, -1�̸� ���º�, 1�̸� �÷��̾� 1 �¸�, 2�̸� �÷��̾� 2 �¸�, Turn -> 1�̸� �÷��̾� 1, 2�̸� �÷��̾� 2, a, b, c�� ���� �Է¹޴� ����, ����, ����, Blank�� ���� ���º� ������ Ȯ�� -> 1�̸� �������, 0�̸� �� ��
	printf("1514 �������� 3���� ƽ���信 ���� ���� ȯ���մϴ�!\n");
	printf("3���� ƽ������ ���� �Ϲ� ƽ����� ����ϰ� ����, ����, ����, �밢�� �� �� ���� ���� ������ �÷��̾ �̱�� �˴ϴ�.\n");
	printf("���� ���� ���� ����� ���� O��, ���߿� ���� ����� ���� X�� ǥ�õ˴ϴ�.\n");
	printf("���� ���� ���ؼ��� (���� �ڸ��� ��), (���� �ڸ��� x��ǥ), (���� �ڸ��� y��ǥ)�� �Է��ϼ���.\n");
	printf("=======================================================================================================================\n");
	printf("�÷��̾� 1�� �̸�: ");
	gets(Name1);						// �� �ڵ忡���� �÷��̾� 1�� ����� �̸��� �Է¹޽��ϴ�.
	printf("�÷��̾� 2�� �̸�: ");
	gets(Name2);						// �� �ڵ忡���� �÷��̾� 1�� ����� �̸��� �Է¹޽��ϴ�.
	while (Det == 0) {
		Print(Arr);						// �� �Լ������� ������ ����Ǵ� ��Ȳ�� ������ݴϴ�.
		if (Turn == 1)
			printf("%s", Name1);
		else if (Turn == 2)
			printf("%s", Name2);
		Scan(Arr, Name1, Name2, Turn);							// Scan ����
		Det = Determine(Arr, Det);						// �� �Լ������� �ºΰ� �������� �Ǻ����ݴϴ�.
		Det = Tie(Arr, Blank, Det);						// �� �Լ������� ������ ���º������� �Ǻ����ݴϴ�.
	}
	Print(Arr);
	if (Det == 1)
		printf("%s�� �¸��Դϴ�!\n", Name1);
	else if (Det == 2)
		printf("%s�� �¸��Դϴ�!\n", Name2);
	else if (Det == -1)
		printf("���º��Դϴ�.\n");
	return 0;
}
void Print(int Arr[][4][4]) {
	for (int i = 1; i <= 4; i++) {
		for (int k = 1; k <= 4; k++) {
			if (k == 2)
				printf("%d��", i);
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
	printf("�� ����: ");			// Scan ù��
	scanf("%d %d %d", &a, &b, &c);
	while ((a < 1 || a > 4) || (b < 1 || b > 4) || (c < 1 || c > 4) || Arr[a][b][c] != 0) {
		printf("���� ���� ���� ��ġ�� �ٽ� �Է����ּ���!\n");
		if (Turn == 1)
			printf("%s", Name1);
		else if (Turn == 2)
			printf("%s", Name2);
		printf("�� ����: ");
		scanf("%d %d %d", &a, &b, &c);
	}
	Arr[a][b][c] = Turn;
	printf("\n");
	Turn = 3 - Turn;
	return Turn;
}
int Determine(int Arr[][4][4], int Det) {
	if (Arr[1][1][1] == Arr[2][2][2] && Arr[2][2][2] == Arr[3][3][3] && Arr[3][3][3] == Arr[4][4][4]) {					// Determine (�����밢��) ù��
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
	}																			// Determine (�����밢��) ����
	for (int i = 1; i <= 4; i++) {
		if (Arr[i][1][1] == Arr[i][2][2] && Arr[i][2][2] == Arr[i][3][3] && Arr[i][3][3] == Arr[i][4][4]) {		// Determine (��밢��) ù��
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
	}																					// Determine (��밢��) ����
	for (int i = 1; i <= 4; i++) {														// Determine (������) ù��
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
	}																				// Determine (������) ����
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