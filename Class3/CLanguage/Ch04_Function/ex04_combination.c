#include<stdio.h>

int factorial(int n);
int combination(int n, int r);

int main() {
	int n, r;

	printf("조합을 계산할 n과 r을 입력하시오: ");
	scanf("%d %d", &n, &r);

	// 1. 결과 출력

	return 0;
}

int factorial(int n) {
	int result = 1;

	for (int i = 1; i <= n; i++)
		result *= i;

	return result;
}

int combination(int n, int r) {
	// 2. C(n, r)의 결과 리턴
}