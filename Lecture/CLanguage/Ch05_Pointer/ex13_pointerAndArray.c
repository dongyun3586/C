#include<stdio.h>
void printArray(int* arr, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", *(arr + i));
	printf("\n");
}

int main() {
	int arr[3][5] = { 0 };
	int* p1 = arr;
	int(*p2)[5] = arr;		// arr == arr[0] == &arr[0] == &arr[0][0]�� ���� �ּҰ�

	printf("%p %d\n", arr, sizeof(arr));
	printf("%p %d\n", &arr, sizeof(&arr));
	printf("%p %d\n", arr[0], sizeof(arr[0]));
	printf("%p %d\n", &arr[0], sizeof(&arr[0]));
	printf("%p %d\n", &arr[0][0], sizeof(&arr[0][0]));

	// �迭�� 0 ~ 14�� �� �ֱ�
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++)
			arr[i][j] = i * 5 + j;

	printf("%d\n", arr[1][3]);
	//printf("%d\n", p1[1][3]);		// int*�� arr�� �ڷ����� �ٸ���.
	printf("%d\n", p2[1][3]);

	// �迭�� ��� ��� ���
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++)
			printf("%d ", arr[i][j]);
	printf("\n\n");

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++)
			printf("%d ", *(p1 + (i * 5) + j));
	printf("\n\n");

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++)
			printf("%d ", p2[i][j]);
	printf("\n\n");

	return 0;
}