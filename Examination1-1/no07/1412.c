#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int nh, nm, ah, am, fh, fm, x, y;

	printf("���� �ð�: ");
	scanf("%d %d", &nh, &nm);
	printf("�˶� �ð�: ");
	scanf("%d %d", &ah, &am);

	fh = ah + 24 - nh;
	fm = am + 60 - nm;
	if (fh >= 24)
		x = fh - 24;
	else
		x = x;
	if (fm >= 60)
		y = fm - 60;
	else
		x = x - 1;

	printf("%d�ð� %d�� ", x, y);

	return 0;
}