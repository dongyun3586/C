#include<stdio.h>

int main() {
	int arr[2][3][5] = { 0 };
	int* p = arr;

	for (int i = 0; i < 2 * 3 * 5; i++)
		*p++ = i;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 5; k++)
				printf("%d ", arr[i][j][k]);
	printf("\n");

	// 포인터로 배열의 모든 요소 출력

	return 0;
}