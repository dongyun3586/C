#include<stdio.h>

int main() {
	// 배열 선언 및 초기화 
	int arr1[5];					// 초기화 없이 선언
	int arr2[5] = { 0,0,0,0,0 };	// arr2[5] = { 0 }
	int arr3[] = { 1,2,3,4,5 };		// 배열을 선언할 때 크기 생략 가능

	// 배열의 특정 요소에 값 대입 => 배열이름[index]로 접근
	arr1[0] = 0;
	arr1[1] = 1;

	// for문으로 배열의 모든 요소(element) 출력하기 
	for (int i = 0; i < 5; i++)
		printf("arr1[%d] = %d\n", i, arr1[i]);

	for (int i = 0; i < 5; i++)
		printf("arr2[%d] = %d\n", i, arr2[i]);

	for (int i = 0; i < 5; i++)
		printf("arr3[%d] = %d\n", i, arr3[i]);

	return 0;
}