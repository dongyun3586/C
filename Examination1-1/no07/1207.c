#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int h, m, ah, am, lh, lm;

	printf("���� �ð�: ");
	scanf("%d %d", &h, &m);
	printf("�˶� �ð�: ");
	scanf("%d %d", &ah, &am);

	if (am > m) {
		lh = h - 1 - ah;
		lm = m - am + 60;
	}
	else {
		lh = h - ah;
		lm = m - am;
	}
	printf("%d�ð� %d�� ", lh, lm);

	return 0;
}