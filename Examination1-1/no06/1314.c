#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a = 0, b = 1, c, n;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	scanf("%d", &n);

	// �� ó�� �� ��� [8��]
	printf("%d %d ", a, b);
	for (int i = 0; i < n; i++) {
		c = a + b;
		a = b;
		b = c;
		printf("%d ", c);
	}

	return 0;
}