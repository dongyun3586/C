#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print2DArray(int arr[][4], int row, int column);
int GCD(int a, int b);

int main() {
	int numArr[10][4] = { 0 };
	int row = sizeof(numArr) / sizeof(numArr[0]);
	int column = sizeof(numArr[0]) / sizeof(int);

	// 2차원 배열의 각행에 2개의 랜덤 숫자 저장
	srand(time(NULL));
	for (int i = 0; i < row; i++)
		for (int j = 0; j < 2; j++)
			numArr[i][j] = rand() % 100 + 1;

	// 2차원 배열의 초기상태 출력
	print2DArray(numArr, row, column);

	// 2차원 배열의 요소로 GCD(Greatest Common Divisor)값 저장
	for (int i = 0; i < row; i++)
		numArr[i][2] = GCD(numArr[i][0], numArr[i][1]);

	// 2차원 배열의 요소로 LCM(Least Common Multiple)값 저장
	for (int i = 0; i < row; i++)
		numArr[i][3] = numArr[i][0] * numArr[i][1] / numArr[i][2];

	// GCD와 LCM값이 저장된 상태 출력
	print2DArray(numArr, row, column);

	return 0;
}

void print2DArray(int arr[][4], int row, int column) {
	printf(" 숫자1 숫자2  GCD   LCM\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++)
			printf("%5d ", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}

int GCD(int a, int b) {
	int t;
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}