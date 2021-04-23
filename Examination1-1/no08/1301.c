#include<stdio.h>

/* 제곱 수열 결과 출력 */
int main() {
	int n, i, ans = 0;

	printf("양의 정수 입력: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		ans = ans * i * i;
	}

	printf("%d", ans);

	return 0;
}