#include<stdio.h>

int main() {
	int arr[] = { 1,2,3,4,5 };
	printf("arr = %p\n", arr);

	printf("\n�迭 ����� �ּ� ���\n");
	for (int i = 0; i < 5; i++)
		printf("%p ", &arr[i]);
	printf("\n");

	// �迭 �̸��� ������ ������ �̿��Ͽ� �� ����� �ּ� ���
	for (int i = 0; i < 5; i++)
		printf("%p ", arr + i);
	printf("\n");

	printf("\n�迭 ����� �� ���\n");
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");

	// �迭 �̸��� ������ ������ �̿��Ͽ� �� ����� �� ���
	for (int i = 0; i < 5; i++)
		printf("%d ", *(arr + i));
	printf("\n");

	return 0;
}