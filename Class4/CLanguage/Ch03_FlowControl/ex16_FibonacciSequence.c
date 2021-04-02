#include<stdio.h>

int main() {
	int n, a = 0, b = 1, next;

	printf("양의 정수를 입력하시오: ");
	scanf("%d", &n);

	// while문을 사용하여 피보나치 수열 출력하기
	while (a <= n) {
		printf("%d ", a);
		next = a + b;
		a = b;
		b = next;
	}

	printf("\n");
	return 0;
}