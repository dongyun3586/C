#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int max = 0, a = 0, b = 1, next = 0;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &max);

	// �� ó�� �� ��� [8��]
	printf("\n");
	while (1) {
		next = a + b;
		a = b;
		b = next;

		if (b > max)
			break;
		else
			printf("%d ", b);
	}

	return 0;
}