#include<stdio.h>

/* 제곱 수열 결과 출력 */
int main() {
	int i = 0, tot = 0, n;

	printf("양의 정수 입력: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (i; i > 0; i--) {
			tot *= i;
		}
	}
	printf("\n%d", tot);

	return 0;
}