#include<stdio.h>

int main() {
	// 배열의 크기를 15로 늘림
	int numArr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int n = sizeof(numArr) / sizeof(int);

	for (int i = 0; i < n; i++)    // 실수로 조건식은 수정하지 못했음
	{
		printf("%d ", numArr[i]);
	}

	return 0;
}