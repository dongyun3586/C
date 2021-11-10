#include<stdio.h>
void printArray(int arr[], int length);
void sort(int arr[], int length);
int main() {
	// ① 변수 선언 [2점]
	int numArr[] = { 4,3,5,2 }; //{ 5,4,3,2,1 };  // { 3, 4, 5, 6, 2, 1 };		// { 4,3,5,2,1 };
	int length = sizeof(numArr) / sizeof(int);

	// ② 함수호출 및 출력 [3점]
	printf("초기 상태: ");
	printArray(numArr, length);
	sort(numArr, length);
	printf("정렬된 상태: ");
	printArray(numArr, length);
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