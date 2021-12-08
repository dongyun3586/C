#include<stdio.h>
#include<Windows.h>
#include<string.h>

void gotoxy(int x, int y);
int pan[10][10] = { 0 };
void omokpan();
int omokdol(int x, int y, int stone);
void input(int* x, int* y);
void gotoxxyy();
int checking();

int main() {


	omokpan();
	int x, y, i = 1;
	int c;
	while (1) {
		input(&x, &y, i);
		i += omokdol(x, y, (i) % 2 + 1);
		if (checking(pan) == 1)
		{
			printf("축하합니다. ");
			printf("게임이 종료되었습니다!!!!!!!!!!!!!\n\n");
			return 0;
		}
	}

	return 0;
}

int checking() {
	int i;
	int j;
	for (i = 2; i < 8; i++) {
		for (j = 0; j < 10; j++) {
			if (pan[j][i - 2] == 1 && pan[j][i - 1] == 1 && pan[j][i] == 1 && pan[j][i + 1] == 1 && pan[j][i + 2] == 1) {
				system("cls");
				printf("\n\n\n\n\n*** WHITE WIN ***\n\n\n\n\n");
				return 1;
			}
			else if (pan[j][i - 2] == 2 && pan[j][i - 1] == 2 && pan[j][i] == 2 && pan[j][i + 1] == 2 && pan[j][i + 2] == 2) {
				system("cls");
				printf("\n\n\n\n\n*** BLACK WIN ***\n\n\n\n\n");
				return 1;
			}

			else if (pan[i - 2][j] == 1 && pan[i - 1][j] == 1 && pan[i][j] == 1 && pan[i + 1][j] == 1 && pan[i + 2][j] == 1) {
				system("cls");
				printf("\n\n\n\n\n*** WHITE WIN ***\n\n\n\n\n");
				return 1;
			}
			else if (pan[i - 2][j] == 2 && pan[i - 1][j] == 2 && pan[i][j] == 2 && pan[i + 1][j] == 2 && pan[i + 2][j] == 2) {
				system("cls");
				printf("\n\n\n\n\n*** BLACK WIN ***\n\n\n\n\n");
				return 1;
			}
		}
	}

	for (i = 2; i < 8; i++) {
		for (j = 2; j < 8; j++) {
			if (pan[j - 2][i - 2] == 1 && pan[j - 1][i - 1] == 1 && pan[j][i] == 1 && pan[j + 1][i + 1] == 1 && pan[j + 2][i + 2] == 1) {
				system("cls");
				printf("\n\n\n\n\n*** WHITE WIN ***\n\n\n\n\n");
				return 1;
			}
			else if (pan[j - 2][i - 2] == 2 && pan[j - 1][i - 1] == 2 && pan[j][i] == 2 && pan[j + 1][i + 1] == 2 && pan[j + 2][i + 2] == 2) {
				system("cls");
				printf("\n\n\n\n\n*** BLACK WIN ***\n\n\n\n\n");
				return 1;
			}

			else if (pan[j + 2][i - 2] == 1 && pan[j + 1][i - 1] == 1 && pan[j][i] == 1 && pan[j - 1][i + 1] == 1 && pan[j - 2][i + 2] == 1) {
				system("cls");
				printf("\n\n\n\n\n*** WHITE WIN ***\n\n\n\n\n");
				return 1;
			}
			else if (pan[j + 2][i - 2] == 2 && pan[j + 1][i - 1] == 2 && pan[j][i] == 2 && pan[j - 1][i + 1] == 2 && pan[j - 2][i + 2] == 2) {
				system("cls");
				printf("\n\n\n\n\n*** BLACK WIN ***\n\n\n\n\n");
				return 1;
			}
		}
	}
	return 0;
}


void input(int* x, int* y, int i) {
	gotoxxyy();
	if (i % 2 == 0)
	{
		printf("WHITE 차례입니다.\n");
	}
	else if (i % 2 == 1)
	{
		printf("BLACK 차례입니다.\n");
	}
	gotoxy(13, 3);
	printf("오목돌을 넣을 위치를 입력하세요(xx,yy) : ");
	char s[10];
	gets_s(s, sizeof(s));
	*y = (s[0] - '0') * 10 + s[1] - '0' - 1;
	*x = (s[2] - '0') * 10 + s[3] - '0' - 1;

}
int omokdol(int x, int y, int stone) {

	if (stone == 2) {
		gotoxy(y, x);
		printf("○");
		pan[y][x] = 2;
	}
	else if (stone == 1) {
		gotoxy(y, x);
		printf("●");
		pan[y][x] = 1;
	}
	return 1;
}

void omokpan() {
	gotoxy(0, 0);
	int i, j;
	for (i = 0; i < 11; i++)
	{
		for (j = 0; j < 11; j++)
		{
			if (i == 0)
			{
				if (j == 0)
				{
					printf("┌ ");
				}
				else if (j == 10)
				{
					printf("┐");
				}
				else
				{
					printf("┬ ");
				}
			}
			else if (i == 10)
			{
				if (j == 0)
				{
					printf("└ ");
				}
				else if (j == 10)
				{
					printf("┘");
				}
				else
				{
					printf("┴ ");
				}
			}
			else
			{
				if (j == 0)
				{
					printf("├ ");
				}
				else if (j == 10)
				{
					printf("┤");
				}
				else {
					printf("┼ ");
				}
			}
		}
		printf("\n");
	}
	for (int i = 0; i < 11; i++) {
		gotoxy(11, i);
		printf("%d", i + 1);
		gotoxy(i, 11);
		printf("%d", i + 1);
	}
	gotoxxyy();
}
void gotoxy(int x, int y) {
	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void gotoxxyy() {
	gotoxy(13, 2);
}