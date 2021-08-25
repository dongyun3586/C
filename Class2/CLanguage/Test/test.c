#include<stdio.h>

int sumArray(int* arr, int n);

int main() {
	int arr[3][5] = { 0 };
	int* p = arr;

	for (int i = 1; i <= 3 * 5; i++)
		*p++ = i;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++)
			printf("%2d ", arr[i][j]);
		printf("\n");
	}
	printf("\n");

	// 행별 합계 출력하기 => for문과 sumArray() 함수 사용

	return 0;
}

int sumArray(int* arr, int n) {
	// 함수 내용 작성하기
}