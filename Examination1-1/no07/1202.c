#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int h, m, a, b, k, l;

	printf("���� �ð�: ");
	scanf("%d %d", &h, &m);
	printf("�˶� �ð�: ");
	scanf("%d %d", &a, &b);

	if (a < h)
		k = 24 + a - h;
	else k = h - a;
	if (m > b) {
		k--;
		l = 60 + b - m;
	}
	else l = m - b;

	printf("%d�ð� %d�� ", k, l);

	return 0;
}