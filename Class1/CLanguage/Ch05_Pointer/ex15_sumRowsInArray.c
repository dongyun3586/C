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

	// �ະ �հ� ����ϱ� => for���� sumArray() �Լ� ���

	return 0;
}

int sumArray(int* arr, int n) {
	// �Լ� ���� �ۼ��ϱ�
}