#include<stdio.h>

int sumOfArray(int* p, int length);

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr_length = sizeof(arr) / sizeof(int);

	// 결과 출력
	printf("arr 배열 요소의 합계: %d\n", sumOfArray(arr, arr_length));

	return 0;
}

// sumOfArray 함수 정의
int sumOfArray(int* p, int length) {
	int sum = 0;
	for (int i = 0; i < length; i++)
		sum += *p++;
	return sum;
}