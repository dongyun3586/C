#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a = 0, b = 1, c = 0, n = 0, t = 0;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &n);

	// �� ó�� �� ��� [8��]
	do {
		if (a > n)
			break;
		else
			printf("%d ", a);
		c = b;
		b = a + b;
		a = c;
	} while (t == 0);

	return 0;
}