#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a, b = 1, c = 0;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	scanf("%d", &a);

	// �� ó�� �� ��� [8��]
	while (b<=a) {
		printf("%d ", c);
		c = b + c;
		b = c + b;
		printf("%d ", b);
	}

	return 0;
}