#include<stdio.h>

int main_ex12_FibonacciSequence() {
	int n, a = 0, b = 1, next;

	printf("�Ǻ���ġ ���� ��� ������? ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("%d ", a);
		next = a + b;
		a = b;
		b = next;
	}

	printf("\n");

	return 0;
}