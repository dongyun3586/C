#include<stdio.h>

int recursiveSum(int a, int b);

int main() {
	int a, b;
	printf("a, b의 값 입력: ");
	scanf("%d%d", &a, &b);

	printf("%d~%d까지의 합 = %d\n", a, b, recursiveSum(a, b));

	return 0;
}

int recursiveSum(int a, int b) {
	if (a == b)
		return a;
	return a + recursiveSum(a + 1, b);
}