#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int h1, h2, m1, m2, hg, mg;

	printf("���� �ð�: ");
	scanf("%d %d", &h1, &m1);
	printf("�˶� �ð�: ");
	scanf("%d %d", &h2, &m2);

	if (h2 > h1)
		hg = h2 - h1;
	else if (h1 > h2)
		hg = 24 + h2 - h1;
	else if (h1 == h2)
		hg = 24;
	if (m2 > m1)
		mg = m2 - m1;
	else if (m1 > m2) {
		mg = 60 + m2 - m1;
		hg--;
	}
	else if (m1 == m2)
		mg = 0;

	printf("%d�ð� %d�� ", hg, mg);

	return 0;
}