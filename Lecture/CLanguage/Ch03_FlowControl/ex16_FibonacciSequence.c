#include<stdio.h>

int main() {
	int n, a = 0, b = 1, next;

	printf("���� ������ �Է��Ͻÿ�: ");
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