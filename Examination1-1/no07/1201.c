#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d, e, f;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	if (a <= c) {
		if (b <= d) {
			f = d - b, e = c - a;
			printf("%d�ð� %d�� ", e, f);
		}
		else {
			f = d - b + 59, e = c - a - 1;
			printf("%d�ð� %d�� ", e, f);
		}
	}
	else {
		if (b <= d) {
			f = d - b, e = c - a+23;
			printf("%d�ð� %d�� ", e, f);
		}
		else {
			f = d - b + 59, e = c - a +22;
			printf("%d�ð� %d�� ", e, f);
		}
	}
	

	return 0;
}