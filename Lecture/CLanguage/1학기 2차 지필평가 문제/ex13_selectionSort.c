#include<stdio.h>
void printArray(int arr[], int length);
void sort(int arr[], int length);
int main() {
	// �� ���� ���� [2��]
	int numArr[] = { 4,3,5,2 }; //{ 5,4,3,2,1 };  // { 3, 4, 5, 6, 2, 1 };		// { 4,3,5,2,1 };
	int length = sizeof(numArr) / sizeof(int);

	// �� �Լ�ȣ�� �� ��� [3��]
	printf("�ʱ� ����: ");
	printArray(numArr, length);
	sort(numArr, length);
	printf("���ĵ� ����: ");
	printArray(numArr, length);
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
	int temp, least;
	for (int i = 0; i < length - 1; i++) {
		least = i;
		for (int j = i + 1; j < length; j++)
			if (arr[least] > arr[j])
				least = j;
		temp = arr[i];
		arr[i] = arr[least];
		arr[least] = temp;
		printArray(arr, length);
	}
}