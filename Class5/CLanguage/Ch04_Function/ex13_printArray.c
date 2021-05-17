#include<stdio.h>

void print1DArray(int arr[], int length);
void print2DArray(int arr[][4], int row, int column);

int main() {
	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
	int arr2[5][4] = { 0 };
	int row = sizeof(arr2) / sizeof(arr2[0]);
	int column = sizeof(arr2[0]) / sizeof(int);

	print1DArray(arr1, sizeof(arr1) / sizeof(int));
	print2DArray(arr2, row, column);

	return 0;
}

void print1DArray(int arr[], int length) {
	printf("1차원 배열 출력\n");
	for (int i = 0; i < length; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void print2DArray(int arr[][4], int row, int column) {
	printf("\n2차원 배열 출력\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}