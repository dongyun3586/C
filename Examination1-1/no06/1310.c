#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a, b, c;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &a);
	b = 0;

	// �� ó�� �� ��� [8��]
	printf("%d ", b);
	for (c = 1; c <= a; c = c + b) {
		printf("%d ", c);
		b = c;
	}

	return 0;
}