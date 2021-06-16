#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
void resetmnt();
void start();
void printmnt();
int returnunsigned(int n);
int checkflg(int x, int y, int shotrng);
void setbugs();
void checkbugs();
int checkend();
int maplct[49][189] = { 0 };
int remainshots = 6000;
int bugX[5] = { 0 };
int bugY[5] = { 0 };
int score = 0;

void resetmnt() {
	system("cls");
	int n = 49;
	while (n) { printf("\n"); n--; }
	int m = 189;
	while (m) { printf(" "); m--; }
}
void start() {
	system("cls");
	int n = 24;
	while (n) { printf("\n"); n--; }
	int m = 84;
	while (m) { printf(" "); m--; }
	printf("�����ձ������ϱ�-�������");
	printf("\n");
	m = 92;
	while (m) { printf(" "); m--; }
	printf("X��������");
	n = 24;
	while (n) { printf("\n"); n--; }
}
int flg[5] = { 0,0,0,0,5 };
void printmnt() {
	for (int i = 0; i < 49; i++) {
		for (int k = 0; k < 189; k++) {
			if (maplct[i][k] == 1) { printf(" "); maplct[i][k] = -2; }
			else if (maplct[i][k] == -2) { printf(" "); }
			else if (maplct[i][k] > 1 && flg[maplct[i][k] - 6] == 0) {
				printf("X"); score += (maplct[i][k] - 5) * remainshots; flg[maplct[i][k] - 6] = -1; maplct[i][k] = -2;
			}
			else if (maplct[i][k] > 1 && flg[maplct[i][k] - 6] > 2) { flg[maplct[i][k]]--; printf("K"); maplct[i][k] = 0; }
			else { printf("0"); }
		}
		printf("\n");
	}
	printf("�ܿ��� : %d\n", remainshots);
	printf("���� : %d\n", score);
	int i = 4;
	while (i) {
		if (flg[i - 1] == -1) {
			if (i == 1) { printf("���带 ��ҽ��ϴ�.\n"); }
			else if (i == 2) { printf("������ ��ҽ��ϴ�.\n"); }
			else if (i == 3) { printf("������ ��ҽ��ϴ�.\n"); }
			else if (i == 4) { printf("������ ��ҽ��ϴ�.\n"); }
		}
		i--;
	}
	if (flg[4] == 2) { printf("���� ��Ҵپƾƾƾƾ�!!!!!!!!!!!!!!!\n"); }
}
int returnunsigned(int n) {
	if (n < 0) { return -n; }
	else { return n; }
}
int checkflg(int x, int y, int shotrng) {
	int checker = 0;
	for (int i = 0; i < 49; i++) {
		for (int k = 0; k < 189; k++) {
			if (returnunsigned(i - x) + returnunsigned(k - y) < shotrng && i < 49 && k < 189 && i >= 0 && k >= 0 && maplct[i][k] != 1) { checker++; }
		}
	}
	if (remainshots - checker < 0) { printf("�ܿ����� ���ڶ��ϴ�. �� ���� ���� �Է��� �ּ���\n�ܿ��� : %d\n", remainshots);  return 0; }
	else {
		remainshots -= checker;
		for (int i = 0; i < 49; i++) {
			for (int k = 0; k < 189; k++) {
				if (returnunsigned(i - x) + returnunsigned(k - y) < shotrng && i < 49 && k < 189 && i >= 0 && k >= 0 && maplct[i][k] != 1) { maplct[i][k] = 1; }
			}
		}
		return 1;
	}
}
void setbugs() {
	int i = 5;
	while (i) {
		if (flg[i - 1] == -1) { bugX[i - 1] = -1; break; }
		bugX[i - 1] = rand() % 188;
		bugY[i - 1] = rand() % 48;
		if (maplct[bugY[i - 1]][bugX[i - 1]] == 1) { continue; }
		i--;
	}
}
void checkbugs() {
	int i = 5;
	while (i) {
		if (maplct[bugY[i - 1]][bugX[i - 1]] == 1) { maplct[bugY[i - 1]][bugX[i - 1]] = i + 5; }
		i--;
	}
}
int checkend() {
	int i = 4, rst = 4;
	while (i) {
		rst += flg[i - 1];
		i--;
	}
	if (rst == 0) { return 0; }
	else { return 1; }
}

int main() {
	srand(time(NULL));
	while (1) {
		start();
		int check = _getch();
		if (check == 'X')//���� ���۸��
		{
			resetmnt();
			break;
		}
	}
	while (remainshots) {
		setbugs();
		int X, Y, shotrng;
		printf("��ǥ : "); scanf("%d%d", &X, &Y);
		int x = X - 1, y = Y - 1;
		printf("�л���� : "); scanf("%d", &shotrng);
		system("cls");
		int flag = checkflg(x, y, shotrng);
		checkbugs();
		if (flag == 1) {
			printmnt();
		}
		if (checkend() == 0) { printf("��! ����� ���� : %d\n", score); break; }
	}
	printf("�ٽ��Ϸ��� ��..���� Ű����");
	return 0;
}