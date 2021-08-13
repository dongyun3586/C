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

	p = arr;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 5; k++)
				printf("%d ", *(p + (i * 3 * 5) + (j * 5) + k));
	//printf("*(p+(%d*3*5)+(%d*5)+%d) = %d\n", i, j, k, *(p+(i*3*5)+(j*5)+k));

	return 0;
}