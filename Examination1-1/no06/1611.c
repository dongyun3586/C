#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a = 0, b = 1, next, n;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &n);

	// �� ó�� �� ��� [8��]
	a = 1, b = 0;
	while (a <= n) {
		printf("%d ", a);
		next = b;
		b = a;
		a = next + b;
	}

	return 0;
}









