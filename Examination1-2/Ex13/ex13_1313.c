#include<stdio.h>
void printArray(int arr[], int length);
void sort(int arr[], int length);
int main() {
	// �� ���� ���� [2��]
	int numArr[] = { 5,4,3,2,1 }; //{ 5,4,3,2,1 };  // { 3, 4, 5, 6, 2, 1 };		// { 4,3,5,2,1 };
	int length = sizeof(numArr) / sizeof(int);

	// �� �Լ�ȣ�� �� ��� [3��]
	printf("�ʱ� ����: ");
	printArray(numArr, length);
	sort(numArr, length);
	
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
	for (int i = 0; i < length; i++) {
		int min = arr[i], min2 = i;
		for (int j = i; j < length; j++) {
			if (arr[i] > arr[j])
				min = arr[j];
			min2 = j;
		}
		int t = arr[i];
		arr[i] = arr[min2];
		arr[min2] = t;
		if(i==length-1)
			printf("���ĵ� ����: ");
		printArray(arr, length);
		else
			printArray(arr, length);
	}
}