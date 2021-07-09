#include<stdio.h>
void printArray(int arr[], int length);
void sort(int arr[], int length);
int main() {
	// ① 변수 선언 [2점]
	int arr[] = { 5,4,3,2,1 }; //{ 5,4,3,2,1 };  // { 3, 4, 5, 6, 2, 1 };		// { 4,3,5,2,1 };
	int length = sizeof(arr) / sizeof(int);

	// ② 함수호출 및 출력 [3점]
	printf("초기 상태: ");
	printArray(arr, length);
	sort(arr, length);

	return 0;
}
// ③ printArray( ) 사용자 정의 함수 [4점]
void printArray(int arr[], int length) {
	for (int i = 0; i < length; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
// ④ sort( ) 사용자 정의 함수 [6점]
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
			printf("정렬된 상태: ");
		printArray(arr, length);
	}
	return;
}