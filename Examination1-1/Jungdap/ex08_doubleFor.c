#include<stdio.h>

/* ���� ���� ��� ��� */
int main() {
	// �� ���� ���� �� ������ ���� �ּ�(����) [2��]
	int n, result = 1;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ���� �Է�: ");
	scanf("%d", &n);

	// �� ó�� [8��]
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			result *= i;
	}

	// �� ��� [2��]
	printf("%d\n", result);

	return 0;
}