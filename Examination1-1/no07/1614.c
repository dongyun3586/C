#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int h1, m1, h2, m2, a, b;

	printf("���� �ð�: ");
	scanf("%d %d", &h1, &m1);
	printf("�˶� �ð�: ");
	scanf("%d %d", &h2, &m2);

	if (h1 <= h2 && m1 <= m2) {
		a = h2 - h1;
		b = m2 - m1;
	}
	else if (h1<h2 && m1>m2) {
		a = h2 - h1 - 1;
		b = 60 - m1 + m2;
	}
	else if (h1 > h2 && m1 < m2) {
		a = 23 - h1 + h2;
	}
	printf("%d�ð� %d�� ", a, b);

	return 0;
}