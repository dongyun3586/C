#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d, e, f;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	if (a > c)
		e = c + 24 - a - (d - b) / 60;
	else 
		e = c - a - (d - b) / 60;
	if (b > d)
		f = d + 60 - b;
	else
		f = d - b;
	printf("%d�ð� %d�� ", e, f);

	return 0;
}