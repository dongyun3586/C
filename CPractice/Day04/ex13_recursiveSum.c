#include<stdio.h>

int recursiveSum(int a, int b);

int main() {
	int a, b;
	printf("a, b�� �� �Է�: ");
	scanf("%d%d", &a, &b);

	printf("%d~%d������ �� = %d\n", a, b, recursiveSum(a, b));

	return 0;
}

int recursiveSum(int a, int b) {
	if (a == b)
		return a;
	return a + recursiveSum(a + 1, b);
}