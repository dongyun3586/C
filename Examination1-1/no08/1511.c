#include<stdio.h>

/* 제곱 수열 결과 출력 */
int main() {
	int sum = 0, i, a, b = 1;

	printf("양의 정수 입력: ");
	scanf("%d", &a);

	for (int i = 1; i <= a; i++) {
		b = 1;
		for (int j = 1; j <= i; j++)
			b *= i;
		sum += b;
	}

	printf("%d", sum);

	return 0;
}