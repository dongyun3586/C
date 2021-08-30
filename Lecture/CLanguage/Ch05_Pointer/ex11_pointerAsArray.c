#include<stdio.h>

int main() {
	int arr1[] = { 10,20,30,40,50 };
	int arr2[] = { 60,70,80,90,100 };
	int* p;

	p = arr1;

	// 배열 요소 출력
	for (int i = 0; i < 5; i++)
		printf("%d ", arr1[i]);
	printf("\n");
	for (int i = 0; i < 5; i++)
		printf("%d ", p[i]);
	printf("\n");
	for (int i = 0; i < 5; i++)
		printf("%d ", *(p + i));
	printf("\n");

	p = arr2;
	for (int i = 0; i < 5; i++)
		printf("%d ", p[i]);
	printf("\n");

	return 0;
}