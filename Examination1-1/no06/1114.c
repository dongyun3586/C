#include<stdio.h>

/* �Ǻ���ġ ���� ��� */
int main() {

	// �� ���� ���� [2��]
	int a, b = 0, c = 1, d = 1;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� ����: ");
	scanf("%d", &a);

	// �� ó�� �� ��� [8��]
	while (b<a&&c<a) {
		if (d == 1) {
			printf("%d ", b);
			b = b + c;
			d = 2;
		}
		if (d == 2) {
			printf("%d ", c);
			c = b + c;
			d = 1;
		}
	}

	return 0;
}