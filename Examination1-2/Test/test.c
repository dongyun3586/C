#include<stdio.h>
void printArray(int arr[], int length);
void sort(int arr[], int length);
int main() {
	// �� ���� ���� [2��]
	int arr[] = { 5,4,3,2,1 }; //{ 5,4,3,2,1 };  // { 3, 4, 5, 6, 2, 1 };		// { 4,3,5,2,1 };
	int length = sizeof(arr) / sizeof(int);

	// �� �Լ�ȣ�� �� ��� [3��]
	printf("�ʱ� ����: ");
	printArray(arr, length);
	sort(arr, length);

	return 0;
}
// �� printArray( ) ����� ���� �Լ� [4��]
void printArray(int arr[], int length) {
	for (int i = 0; i < length; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
// �� sort( ) ����� ���� �Լ� [6��]
void sort(int arr[], int length) {
	int min, tmp;
	for (int i = 0; i < length - 1; i++) {
		min = i;
		for (int j = i + 1; j < length; j++)
			if (arr[j] < arr[min])
				min = j;
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
		if (i == length - 2)
			printf("���ĵ� ����: ");
		printArray(arr, length);
	}
	return;
}