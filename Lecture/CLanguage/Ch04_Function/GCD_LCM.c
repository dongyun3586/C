#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print2DArray(int arr[][4], int row, int column);
int GCD(int a, int b);

int main() {
	int numArr[10][4] = { 0 };
	int row = sizeof(numArr) / sizeof(numArr[0]);
	int column = sizeof(numArr[0]) / sizeof(int);

	// 2���� �迭�� ���࿡ 2���� ���� ���� ����
	srand(time(NULL));
	for (int i = 0; i < row; i++)
		for (int j = 0; j < 2; j++)
			numArr[i][j] = rand() % 100 + 1;

	// 2���� �迭�� �ʱ���� ���
	print2DArray(numArr, row, column);

	// 2���� �迭�� ��ҷ� GCD(Greatest Common Divisor)�� ����
	for (int i = 0; i < row; i++)
		numArr[i][2] = GCD(numArr[i][0], numArr[i][1]);

	// 2���� �迭�� ��ҷ� LCM(Least Common Multiple)�� ����
	for (int i = 0; i < row; i++)
		numArr[i][3] = numArr[i][0] * numArr[i][1] / numArr[i][2];

	// GCD�� LCM���� ����� ���� ���
	print2DArray(numArr, row, column);

	return 0;
}

void print2DArray(int arr[][4], int row, int column) {
	printf(" ����1 ����2  GCD   LCM\n");
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