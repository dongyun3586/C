#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int h, m, h2, m2;

	printf("���� �ð�: ");
	scanf("%d %d", &h, &m);
	printf("�˶� �ð�: ");
	scanf("%d %d", &h2, &m2);

	int h3 = h - h2, m3 = m - m2;
	if (h - h2 < 0) h3 = h3 * -1;
	else if (h - h2 > 0) h3 = h2 + 24 - h;
	else if (m - m2 < 0)m3 = m - m2 + 60;
	h3 = h3 - 1;

	printf("%d�ð� %d�� ", h3, m3);

	return 0;
}