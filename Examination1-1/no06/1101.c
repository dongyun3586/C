#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	int a = 1, b = 0, c = 0, n;

	printf("양의 정수: ");
	scanf("%d", &n);

	for (int i = 0; ; i++) {
		if (c >= n)
			break;
		printf("%d ", c);
		c = a + b;
		a = b;
	}

	return 0;
}