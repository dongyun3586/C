#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d, k, l;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	if (a >= c) {
		if (b > d) {
			k = 23 - a + c;
			l = 60 - b - d;
		}
		else {
			k = 24 - a + c;
			l = d - b;
		}
	}
	else {
		if (b > d) {
			k = c - a - 1;
			l = 60 - b + d;
		}
		else {
			k = c - a;
			l = d - b;
		}
	}

	printf("%d�ð� %d�� ", k, l);

	return 0;
}