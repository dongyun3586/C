#include <stdio.h>

void printCombination2(int A[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			printf("%d, %d\n", A[i], A[j]);
}

void printCombination3(int A[], int n) {
	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++)
			for (int k = j + 1; k < n; k++)
				printf("%d, %d, %d\n", A[i], A[j], A[k]);
}

int main() {

	int A[] = { 1,2,3,4 };

	printCombination2(A, 4);

	// 반복문을 이용한 조합의 문제점
	// n이 변하는 것은 상관 없으나, 뽑는 개수가 달라지면 반복문을 추가해야 한다.
	printCombination3(A, 4);

	return 0;
}