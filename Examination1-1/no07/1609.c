#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d, x, y;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	if (b >= d) {
		c = c - 1;
		x = b - d;
		if (a >= c)
			y = c + 24 - a;
		else
			y = a - c;		// y = c - a; ����
	}
	else {
		x = d - b;
		if (a >= c)
			y = c + 24 - a;
		else
			y = a - c;		// y = c - a; ����
	}
	printf("%d�ð� %d�� ", y, x);

	return 0;
}