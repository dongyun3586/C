#include<stdio.h>

int main() {
	int arr[] = { 10,20,30,40,50 };
	int* p;

	p = arr;
	// �迭 ��� ���
	for (int i = 0; i < 5; i++)
		printf("arr[%d]=%d\n", i, arr[i]);
	for (int i = 0; i < 5; i++)
		printf("p[%d]=%d\n", i, p[i]);

	// �迭 ��Ұ� ��ȭ
	for (int i = 0; i < 5; i++)
		p[i] *= 10;

	// �迭 ��� ���
	for (int i = 0; i < 5; i++)
		printf("arr[%d]=%d\n", i, arr[i]);
	for (int i = 0; i < 5; i++)
		printf("p[%d]=%d\n", i, p[i]);

	return 0;
}