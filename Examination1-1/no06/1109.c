#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int n, t, a = 0, b = 1, next;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &n);

	// �� ó�� �� ��� [8��]
	printf("%d %d ", a, b);
	while (1) {
		if (next > n)
			break;
		else {
			printf("%d ", next);
			t = next;
			next = next + b;
			b = t;
		}
	}

	return 0;
}