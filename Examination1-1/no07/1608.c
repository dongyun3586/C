#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	// ��) ���� ���� [2��]
	int a, b, c, d, e, f;

	// �� �Է� ���� �ȳ� �� �Է� �ޱ� [2��]
	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	if (a > 12 && b > d) {
		e = 24 - a - 1 + c;
		f = b - d;
		printf("%d�ð� %d��", e, f);
	}
	else if (a > 12 && b < d) {
		e = 24 - a + c;
		f = d - b;
		printf("%d�ð� %d��", e, f);
	}
	else if (a < 12 && b < d) {
		e = c - a;
		f = b - d;
		printf("%d�ð� %d��", e, f);
	}
	else if (a<12 && b>d) {
		e = c - a - 1;
		f = d - b;
		printf("%d�ð� %d��", e, f);
	}


	return 0;
}