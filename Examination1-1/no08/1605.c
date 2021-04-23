#include<stdio.h>

/* 제곱 수열 결과 출력 */
int main() {
	int a, b, n, j, i, sum;

	printf("양의 정수 입력: ");
	scanf("%d", &n);
	sum = 1; a = 1; b = 1;

	while (a <= n) {
		for (i = 1; i <= a; i++) {
			b *= a;
		}
		sum *= b;
		b = 1;
		a++;
	}

	printf("\n%d", sum);

	return 0;
}