#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a = 0, b = 1, n, i = 0, t;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &n);

	// �� ó�� �� ��� [8��]
	printf("0 1 ");
	while (b <= n) {
		t = a + b;
		a = b, b = t;
		printf("%d ", b);
	}

	return 0;
}