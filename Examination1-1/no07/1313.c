#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d, e, f;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	if (d >= b)
		f = d - b;
	else {
		f = d - b + 60;
		c--;
	}
	if (c >= a)
		e = c - a;
	else
		e = c - a + 24;
	printf("%d�ð� %d�� ", e, f);

	return 0;
}