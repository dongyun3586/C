#include<stdio.h>

int main() {
	int n, a = 0, b = 1, next;

	printf("양의 정수를 입력하시오: ");
	scanf("%d", &n);

	while (a <= n) {
		printf("%d ", a);
		next = a + b;
		a = b;
		b = next;
	}
	
	printf("\n");
	return 0;
}