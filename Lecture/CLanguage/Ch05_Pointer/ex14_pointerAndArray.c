#include<stdio.h>

int main() {
	int arr[2][3][5] = { 0 };
	int* p = arr;

	for (int i = 0; i < 2 * 3 * 5; i++)
		*p++ = i;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 5; k++)
				printf("%d ", arr[i][j][k]);	// printf("arr[%d][%d][%d] = %d\n", i, j, k, arr[i][j][k]);
	printf("\n");

	p = arr;	// p를 arr값으로 초기화하지 않으면 p에 저장된 주소가 배열의 범위를 벗어났기 때문에 다시 간접접근하면 쓰레기 값이 출력된다.
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 5; k++)
				printf("%d ", *(p + (i * 3 * 5) + (j * 5) + k));
	//printf("*(p+(%d*3*5)+(%d*5)+%d) = %d\n", i, j, k, *(p+(i*3*5)+(j*5)+k));

	printf("\n");

	for (int i = 0; i < 2 * 3 * 5; i++)
		printf("%d ", *p++);



	return 0;
}