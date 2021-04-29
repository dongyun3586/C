#include<stdio.h>

/* 제곱 수열 결과 출력 */
int main() {
	int n, sum = 1;

	printf("양의 정수 입력: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++)
			sum *= j;
	}

	printf("%d", sum);

	return 0;
}