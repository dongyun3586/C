#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	int a, b, t, n, m;
	a = 0, b = 1, n = a + b;

	printf("양의 정수: ");
	scanf("%d", &t);

	printf("%d %d ", a, b);
	for (int i = 0; i <= t; i++) {
		m = b;
		b = n;
		a = m;
		n = a + b;
		if (n > t)
			break;
		printf("%d ", n);
	}

	return 0;
}