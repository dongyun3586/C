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
	if (a > c)
		c = c + 24;
	if (b > d) {
		n = 60 + d - b;
		c--;
	}

	m = c - a;
		

	// �� ��� [3��]
	printf("%d�ð� %d�� ", m, n);

	return 0;
}