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
	double camera[3] = { 0, 0, -10 };																															//카메라 위치 초기값 정의
	double theta = 0, phi = 0;																																	//theta: y축 기준 회전각, phi: x축 기준 회전각
	int pcube3[8][3] = { {1, 1, 1}, {1, 1, -1}, {1, -1, 1}, {1, -1, -1}, {-1, 1, 1}, {-1, 1, -1}, {-1, -1, 1}, {-1, -1, -1} };									//정육면체 꼭짓점 좌표(3차원)
	double pcube2[8][2];																																		//변환 후 정육면체 꼭짓점 좌표(2차원)
	int ecube[12][2] = { {0, 1}, {0, 2}, {0, 4}, {1, 3}, {1, 5}, {2, 3}, {2, 6}, {3, 7}, {4, 5}, {4, 6}, {5, 7}, {6, 7} };										//정육면체 모서리
	int screen[101][101];																																		// 0 1로 별 찍을 위치 결정
	char c;																																						//키보드 입력
	printf("화살표로 정육면체 회전, WASD로 카메라 위치 조정, Q, E는 원근계수 조절입니다. SPACE 키를 눌러 종료합니다. 글자 크기를 10 이하로 줄여주세요.");		//설명
	Sleep(2000);																																				//다음 줄에서 자동으로 설명 지워지기 때문에 정지
	system("mode con cols=203 lines=103");																														//콘솔 창 크기 조절
	while (1) {																																					//무한반복
		if (_kbhit()) {
			c = _getch();
			if (c == -32) {
				c = _getch();
				switch (c) {
				case LEFT:																																		//y축 기준 회전각 감소
					theta -= 0.05;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case RIGHT:																																		//y축 기준 회전각 증가
					theta += 0.05;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case UP:																																		//x축 기준 회전각 감소
					phi -= 0.05;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case DOWN:																																		//x축 기준 회전각 증가
					phi += 0.05;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				}
			}
			else
				switch (c) {
				case Q:																																			//원근계수 감소
					e--;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case E:																																			//원근계수 증가
					e++;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case W:																																			//카메라 y좌표 증가
					camera[1] += 0.05;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case A:																																			//카메라 x좌표 감소
					camera[0] -= 0.05;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case S:																																			//카메라 y좌표 감소
					camera[1] -= 0.05;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case D:																																			//카메라 x좌표 증가
					camera[0] += 0.05;
					render(size, e, theta, phi, pcube3, pcube2, camera, ecube, screen);
					break;
				case SPACE:																																		//종료
					return 0;
				}
		}
	}
}

void transform(int d3[][3], double camera[], double* d2, double theta, double phi, int size, int e) {
	int t = 8;
	double temp1[3], temp2[3];
	for (int i = 0; i < t; i++) {
		temp1[0] = cos(theta * PI) * (double)d3[i][0] + sin(theta * PI) * (double)d3[i][2];																		//theta 기준 회전변환
		temp1[1] = (double)d3[i][1];
		temp1[2] = -sin(theta * PI) * (double)d3[i][0] + cos(theta * PI) * (double)d3[i][2];
		temp2[0] = temp1[0];																																	//phi 기준 회전변환
		temp2[1] = cos(phi * PI) * temp1[1] - sin(phi * PI) * temp1[2];
		temp2[2] = sin(phi * PI) * temp1[1] + cos(phi * PI) * temp1[2];
		*(d2 + 2 * i) = (-temp2[0] + camera[0]) * (1 + ((-temp2[2] + camera[2]) / e)) * size;																	//원점 기준 좌표계를 카메라 기준 좌표계로 변환 후 x좌표 + z좌표(1+원근계수)
		*(d2 + 2 * i + 1) = (temp2[1] + camera[1]) * (1 + ((-temp2[2] + camera[2]) / e)) * size;																//원점 기준 좌표계를 카메라 기준 좌표계로 변환 후 y좌표 + z좌표(1+원근계수)
	}
}//회전변환, 좌표계변환, 투영 및 원근감 조절

void makescreen(double p2[][2], int e2[][2], int* screen) {
	double a, b;
	int min, max, range;
	for (int j = 0; j < 101; j++)
		for (int k = 0; k < 101; k++)
			*(screen + 101 * j + k) = 0;
	for (int i = 0; i < 12/*sizeof(e2) / 8*/; i++) {
		if (fabs(p2[e2[i][0]][0] - p2[e2[i][1]][0]) >= fabs(p2[e2[i][0]][1] - p2[e2[i][1]][1])) {				//if Δx > Δy: 좌표 기준
			a = (double)(p2[e2[i][0]][1] - p2[e2[i][1]][1]) / (double)(p2[e2[i][0]][0] - p2[e2[i][1]][0]);		//기울기
			b = p2[e2[i][0]][1] - a * p2[e2[i][0]][0];															//y절편
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
				/*screen[-range + 50][dom + 50] = 1;*/															//screen[-y + 50][x + 50]에 체크
				*(screen + -101 * range + dom + 5100) = 1;														//screen[x + 50][y + 50]에 체크
			}
		}
		else {																									//if 기울기 < 1: x=ay+b
			a = (double)(p2[e2[i][0]][0] - p2[e2[i][1]][0]) / (double)(p2[e2[i][0]][1] - p2[e2[i][1]][1]);		//기울기
			b = p2[e2[i][0]][0] - a * p2[e2[i][0]][1];															//x절편
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
				*(screen + range - 101 * dom + 5100)/* screen[-dom + 50][range + 50] */ = 1;					//screen[x + 50][y + 50]에 체크
			}
		}
	}
}
//0또는 1로 선분 나타내기

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
//만든 선분 출력하기

void render(int size, int e, double theta, double phi, int pPlt3[][3], double pPlt2[][2], double camera[], int ePlt[][2], int screen[][101]) {
	transform(pPlt3, camera, *pPlt2, theta, phi, size, e);
	makescreen(pPlt2, ePlt, *screen);
	figure(screen);
}