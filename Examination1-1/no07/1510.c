#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d, p, q;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	p = c - a;
	q = d - b;
	if (p < 0)
		p += 24;
	if (q < 0) {
		q += 60;
		p--;
	}
	printf("%d�ð� %d�� ", p, q);

	return 0;
}