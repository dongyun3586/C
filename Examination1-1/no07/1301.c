#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int nh, nm, ah, am, dh, dm;

	printf("���� �ð�: ");
	scanf("%d %d", &nh, &nm);
	printf("�˶� �ð�: ");
	scanf("%d %d", &ah, &am);

	dh = ah - nh;
	dm = am - nm;
	if (dm < 0) {
		dh--;
		dm += 60;
	}
	if (dh < 0)
		dh += 24;

	printf("%d�ð� %d�� ", dh, dm);

	return 0;
}