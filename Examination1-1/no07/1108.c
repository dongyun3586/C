#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d, e, f;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	if (b > d) {
		f = d - b;
		if (a <= c)
			e = c - a;
		else
			e = c + 12 - a;
	}
	else {
		f = d + 60 - b;
		if (a < c)
			e = c - a - 1;
		else
			e = c - a + 11;
	}
	printf("%d�ð� %d�� ", e,f);

	return 0;
}