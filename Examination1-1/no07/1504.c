#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	// ��) ���� ���� [2��]
	int a, b, c, d, e, f;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	scanf("%d %d %d %d", &a, &b, &c, &d);

	printf("���� �ð�: %d %d", a, b);
	printf("�˶� �ð�: %d %d", c, d);

	// �� ó�� [8��]
	if (a > c)
		e = 24 - a + c;
	else
		e = c - a;

	if (b > d) {
		f = 60 - b + d;
		e--;
		//if (e < 0) e += 24; <- ����
	}
	else
		f = d - b;

	printf("%d�ð� %d�� ", e, f);

	return 0;
}