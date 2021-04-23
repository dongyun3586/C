#include<stdio.h>

/* 제곱 수열 결과 출력 */
int main() {
	int n, answer = 1;

	printf("양의 정수 입력: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		mul = 1;
		for (int j = 0; j <= n; j++)
			mul *= n;
		answer *= mul;
			
	}

	printf("%d", answer);

	return 0;
}