#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d, e, t;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	if (c > a) {
		if (d > b) {
			e = c - a;
			t = d - b;
			printf("%d�ð� %d�� ", e, t);
		}
		else if (b > d) {
			e = c - a - 1;
			t = b - d;
			printf("%d�ð� %d�� ", e, t);
		}
	}
	else if (a > c) {
		if (d > b) {
			e = 24- a+b;
			t = d - b;
			printf("%d�ð� %d�� ", e, t);
		}
		else if (b > d) {
			e = 24- a+b - 1;
			t = b - d;
			printf("%d�ð� %d�� ", e, t);
		}
	}
	

	return 0;
}