#include<stdio.h>

int get_sum1(int arr[], int n);
int get_sum2(int* p, int n);

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("get_sum1(arr, 10) = %d\n", get_sum1(arr, 10));
	printf("get_sum2(arr, 10) = %d\n", get_sum2(arr, 10));
	return 0;
}

int get_sum1(int arr[], int n) {
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += arr[i];

	return sum;
}

int get_sum2(int* p, int n) {
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += *p++;		// // *p을 sum에 더하고 p의 주소를 1 증가시킴.

	return sum;
}