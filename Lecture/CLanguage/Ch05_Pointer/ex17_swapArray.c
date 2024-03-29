#include<stdio.h>
void print2DArray(int* arr, int n, char* arrName);
void swap2DArray(int** arr1, int** arr2);

int main() {
	int A[2][3] = { 1,2,3,4,5,6 };
	int B[2][3] = { 10,20,30,40,50,60 };

	/*int(*pA)[3] = A;
	int(*pB)[3] = B;*/

	int* pA = A[0];
	int* pB = B[0];

	print2DArray(pA, 6, "pA");
	print2DArray(pB, 6, "pB");

	swap2DArray(&pA, &pB);

	print2DArray(pA, 6, "pA");
	print2DArray(pB, 6, "pB");

	return 0;
}

void print2DArray(int* arr, int n, char* arrName) {
	printf("%s : ", arrName);
	for (int i = 0; i < n; i++)
		printf("%2d ", *(arr + i));
	printf("\n");
}

void swap2DArray(int** arr1, int** arr2) {
	int* temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}

