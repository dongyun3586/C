#include<stdio.h>

int main() {
	int arr[] = { 1,2,3,4,5 };
	printf("arr = %p\n", arr);

	printf("\n배열 요소의 주소 출력\n");
	for (int i = 0; i < 5; i++)
		printf("%p ", &arr[i]);
	printf("\n");

	// 배열 이름과 포인터 연산을 이용하여 각 요소의 주소 출력
	for (int i = 0; i < 5; i++)
		printf("%p ", arr + i);
	printf("\n");

	printf("\n배열 요소의 값 출력\n");
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");

	// 배열 이름과 포인터 연산을 이용하여 각 요소의 값 출력
	for (int i = 0; i < 5; i++)
		printf("%d ", *(arr + i));
	printf("\n");

	return 0;
}