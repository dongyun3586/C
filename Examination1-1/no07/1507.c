#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	// ��) ���� ���� [2��]
	int a, b, c, d, m, n;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	// �� ó�� [8��]
	if (a > c) {
		if (d >= b) {
			m = c + 24 - a;
			n = d - b;
		}
		if (d < b) {
			m = c + 23 - a;
			n = d + 60 - b;
		}
	}
	if (a <= c) {
		if (d > b) {
			m = c - a;
			n = d - b;
		}
		if (d < b) {
			m = c - 1 - a;
			n = d + 60 - b;
		}
	}

	// �� ��� [3��]
	printf("%d�ð� %d�� ", m, n);

	return 0;
}