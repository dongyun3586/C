#include<stdio.h>

int main_ex16_fibonacciSequence() {
	int n, a = 0, b = 1, next;

	printf("���� ������ �Է��Ͻÿ�: ");
	scanf("%d", &n);

	// while���� ����Ͽ� �Ǻ���ġ ���� ����ϱ�
	while (a <= n) {
		printf("%d ", a);
		next = a + b;
		a = b;
		b = next;
	}

	printf("\n");
	return 0;
}