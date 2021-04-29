#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int n, a = 0, b = 1;

	scanf("%d", &n);

	while (1) {
		if (a > n)
			break;
		printf("%d ", a);
		if (b > n)
			break;
		printf("%d ", b);
		a = a + b;
		b = a + b;
	}

	return 0;
}