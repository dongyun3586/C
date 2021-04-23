#include<stdio.h>

/* 제곱 수열 결과 출력 */
int main() {
	int n;
	long long sum = 1;

	printf("양의 정수 입력: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int num = 1;
		for (int j = 1; j <= i; j++)
			num *= i;
		sum *= num;
	}

	printf("%d", sum);

	return 0;
}