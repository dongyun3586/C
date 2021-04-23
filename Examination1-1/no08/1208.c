#include<stdio.h>

/* 제곱 수열 결과 출력 */
int main() {
	int sum = 0;
	int sgsum = 1;
	int n;

	printf("양의 정수 입력: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
			sgsum *= i;
		sum *= sgsum;
		sgsum = 0;
	}

	printf("%d", sum);

	return 0;
}