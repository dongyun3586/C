#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int fibo1 = 0, fibo2 = 1, fibo, n;

	printf("양의 정수: ");
	scanf("%d", &n);

	printf("%d %d ", fibo1, fibo2);
	while (1) {
		fibo = fibo1 + fibo2;
		if (fibo <= n) {
			printf("%d ", fibo);
			fibo1 = fibo2;
			fibo2 = fibo;
		}
		else {
			break;
		}
	}

	return 0;
}