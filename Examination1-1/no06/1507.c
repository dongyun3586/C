#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int k, c, a = 0, b = 1;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &k);

	// �� ó�� �� ��� [8��]
	do {
		c = a + b;
		a = b;
		b = c;
		printf("%d ", c);
	} while (c <= k);

	return 0;
}