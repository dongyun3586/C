#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, x, y, h, m;

	printf("���� �ð�: ");
	scanf("%2d %2d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%2d %2d", &x, &y);

	if (b > y) {
		y += 60;
		x--;
		if (a > x)
			x += 24;
	}
	else {
		if (a > x)
			x += 24;
		
	}
	printf("\n");
	m = y - b;
	h = x - a;
	printf("%d�ð� %d�� ", h, m);

	return 0;
}