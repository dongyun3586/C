#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a, b, c = 0, d = 1;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &a);

	// �� ó�� �� ��� [8��]
	printf("0 1 ");
	while (b<=a) {
		b = c + d;
		c = d;
		d = b;
		printf("%d ", b);
		}
	}

	return 0;
}