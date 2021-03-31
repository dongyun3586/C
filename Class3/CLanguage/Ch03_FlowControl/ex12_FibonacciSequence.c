#include<stdio.h>

int main_ex12_FibonacciSequence() {
	int n;
	long long int a = 0, b = 1, next;

	printf("피보나치 수열 출력 개수는? ");
	scanf("%d", &n);

	// for문을 이용하여 피보나치 수열 반복 출력
	for (int i = 0; i < n; i++) {
		printf("%lld ", a);
		next = a + b;
		a = b;
		b = next;
	}

	printf("\n");
	return 0;
}