#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int h, s, ah, as, x, y;

	printf("���� �ð�: ");
	scanf("%d %d", &h, &s);
	printf("\n�˶� �ð�: ");
	scanf("%d %d", &ah, &as);

	if (as < s) {
		y = 60 + as - s;
		if (ah <= h)
			x = 24 + ah - h - 1;
		else
			x = ah - h;
	}
	else {
		y = as - s;
		if (ah < h)
			x = 24 + ah - h;
		else
			x = ah - h;
	}
	printf("%d�ð� %d�� ", x, y);

	return 0;
}