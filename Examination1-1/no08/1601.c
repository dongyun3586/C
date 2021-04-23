#include<stdio.h>

/* 제곱 수열 결과 출력 */
int main() {
	int n;
	long long int a = 1, b = 1;

	printf("양의 정수 입력: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			a *= i;
		}
		b *= a;
		a = 1;
	}
	printf("%lld\n", b);

	return 0;
}