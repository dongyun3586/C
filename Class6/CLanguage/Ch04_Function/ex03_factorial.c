#include<stdio.h>

int factorial(int n);

int main() {
	int n;

	printf("팩토리얼 값? ");
	scanf("%d", &n);

	printf("%d!= %d\n", n, factorial(n));

	return 0;
}

int factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++)
		result *= i;

	return result;
}