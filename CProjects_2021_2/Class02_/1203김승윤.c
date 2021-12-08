#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define W 87
#define A 65
#define S 83
#define D 68
#define Q 81
#define E 69
#define SPACE 32
#define PI 3.1415926
void transform(int d3[][3], double camera[], double* d2, double theta, double phi, int size, int e);
void makescreen(double p2[][2], int e2[][2], int* screen);
void figure(int array[][101]);
void render(int size, int e, double theta, double phi, int pPlt3[][3], double pPlt2[][2], double camera[], int ePlt[][2], int screen[][101]);
int main() {
	int size = 30;
	int e = 30;
	double camera[3] = { 0, 0, -10 };																															//ī�޶� ��ġ �ʱⰪ ����
	double theta = 0, phi = 0;																																	//theta: y�� ���� ȸ����, phi: x�� ���� ȸ����
	int pcube3[8][3] = { {1, 1, 1}, {1, 1, -1}, {1, -1, 1}, {1, -1, -1}, {-1, 1, 1}, {-1, 1, -1}, {-1, -1, 1}, {-1, -1, -1} };									//������ü ������ ��ǥ(3����)
	double pcube2[8][2];																																		//��ȯ �� ������ü ������ ��ǥ(2����)
	int ecube[12][2] = { {0, 1}, {0, 2}, {0, 4}, {1, 3}, {1, 5}, {2, 3}, {2, 6}, {3, 7}, {4, 5}, {4, 6}, {5, 7}, {6, 7} };										//������ü �𼭸�
	int screen[101][101];																																		// 0 1�� �� ���� ��ġ ����
	char c;																																						//Ű���� �Է�
	printf("ȭ��ǥ�� ������ü ȸ��, WASD�� ī�޶� ��ġ ����, Q, E�� ���ٰ�� �����Դϴ�. SPACE Ű�� ���� �����մϴ�. ���� ũ�⸦ 10 ���Ϸ� �ٿ��ּ���.");		//����
	Sleep(2000);																																				//���� �ٿ��� �ڵ����� ���� �������� ������ ����
	system("mode con cols=203 lines=103");																														//�ܼ� â ũ�� ����
	while (1) {																																					//���ѹݺ�
		if (_kbhit()) {
			c = _getch();
			if (c == -32) {
				c = _getch();
				switch (c) {
				case LEFT:																																		//y�� ���� ȸ���� ����
					theta -= 0.05;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case RIGHT:																																		//y�� ���� ȸ���� ����
					theta += 0.05;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case UP:																																		//x�� ���� ȸ���� ����
					phi -= 0.05;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case DOWN:																																		//x�� ���� ȸ���� ����
					phi += 0.05;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				}
			}
			else
				switch (c) {
				case Q:																																			//���ٰ�� ����
					e--;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case E:																																			//���ٰ�� ����
					e++;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case W:																																			//ī�޶� y��ǥ ����
					camera[1] += 0.05;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case A:																																			//ī�޶� x��ǥ ����
					camera[0] -= 0.05;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case S:																																			//ī�޶� y��ǥ ����
					camera[1] -= 0.05;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case D:																																			//ī�޶� x��ǥ ����
					camera[0] += 0.05;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case SPACE:																																		//����
					return 0;
				}
		}
	}
}

void transform(int d3[][3], double camera[], double* d2, double theta, double phi, int size, int e) {
	int t = 8;
	double temp1[3], temp2[3];
	for (int i = 0; i < t; i++) {
		temp1[0] = cos(theta * PI) * (double)d3[i][0] + sin(theta * PI) * (double)d3[i][2];																		//theta ���� ȸ����ȯ
		temp1[1] = (double)d3[i][1];
		temp1[2] = -sin(theta * PI) * (double)d3[i][0] + cos(theta * PI) * (double)d3[i][2];
		temp2[0] = temp1[0];																																	//phi ���� ȸ����ȯ
		temp2[1] = cos(phi * PI) * temp1[1] - sin(phi * PI) * temp1[2];
		temp2[2] = sin(phi * PI) * temp1[1] + cos(phi * PI) * temp1[2];
		*(d2 + 2 * i) = (-temp2[0] + camera[0]) * (1 + ((-temp2[2] + camera[2]) / e)) * size;																	//���� ���� ��ǥ�踦 ī�޶� ���� ��ǥ��� ��ȯ �� x��ǥ + z��ǥ(1+���ٰ��)
		*(d2 + 2 * i + 1) = (temp2[1] + camera[1]) * (1 + ((-temp2[2] + camera[2]) / e)) * size;																//���� ���� ��ǥ�踦 ī�޶� ���� ��ǥ��� ��ȯ �� y��ǥ + z��ǥ(1+���ٰ��)
	}
}//ȸ����ȯ, ��ǥ�躯ȯ, ���� �� ���ٰ� ����

void makescreen(double p2[][2], int e2[][2], int* screen) {
	double a, b;
	int min, max, range;
	for (int j = 0; j < 101; j++)
		for (int k = 0; k < 101; k++)
			*(screen + 101 * j + k) = 0;
	for (int i = 0; i < 12/*sizeof(e2) / 8*/; i++) {
		if (fabs(p2[e2[i][0]][0] - p2[e2[i][1]][0]) >= fabs(p2[e2[i][0]][1] - p2[e2[i][1]][1])) {				//if ��x > ��y: ��ǥ ����
			a = (double)(p2[e2[i][0]][1] - p2[e2[i][1]][1]) / (double)(p2[e2[i][0]][0] - p2[e2[i][1]][0]);		//����
			b = p2[e2[i][0]][1] - a * p2[e2[i][0]][0];															//y����
			if (p2[e2[i][0]][0] >= p2[e2[i][1]][0]) {
				max = p2[e2[i][0]][0];
				min = p2[e2[i][1]][0];
			}
			else {
				max = p2[e2[i][1]][0];
				min = p2[e2[i][0]][0];
			}
			for (int dom = min; dom <= max; dom++) {
				range = (int)round(a * (double)dom + b);														//y=ax+b, 	
				/*screen[-range + 50][dom + 50] = 1;*/															//screen[-y + 50][x + 50]�� üũ
				*(screen + -101 * range + dom + 5100) = 1;														//screen[x + 50][y + 50]�� üũ
			}
		}
		else {																									//if ���� < 1: x=ay+b
			a = (double)(p2[e2[i][0]][0] - p2[e2[i][1]][0]) / (double)(p2[e2[i][0]][1] - p2[e2[i][1]][1]);		//����
			b = p2[e2[i][0]][0] - a * p2[e2[i][0]][1];															//x����
			if (p2[e2[i][0]][1] >= p2[e2[i][1]][1]) {
				max = p2[e2[i][0]][1];
				min = p2[e2[i][1]][1];
			}
			else {
				max = p2[e2[i][1]][1];
				min = p2[e2[i][0]][1];
			}
			for (int dom = min; dom <= max; dom++) {
				range = (int)round(a * (double)dom + b);														//y=ax+b, 	
				*(screen + range - 101 * dom + 5100)/* screen[-dom + 50][range + 50] */ = 1;					//screen[x + 50][y + 50]�� üũ
			}
		}
	}
}
//0�Ǵ� 1�� ���� ��Ÿ����

void figure(int array[][101]) {
	for (int j = 0; j < 101; j++) {
		printf(" \n");
		for (int k = 0; k < 101; k++) {
			if (array[j][k] == 1)
				printf(" *");
			else
				printf("  ");
		}
	}
}
//���� ���� ����ϱ�

void render(int size, int e, double theta, double phi, int pPlt3[][3], double pPlt2[][2], double camera[], int ePlt[][2], int screen[][101]) {
	transform(pPlt3, camera, *pPlt2, theta, phi, size, e);
	makescreen(pPlt2, ePlt, *screen);
	figure(screen);
}