#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d, e;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	if (a > c) {
		e = 60 * a + b - 60 * c - d;
		printf("%d�ð� %d�� ", (60 * 24 - e) / 60, (60 * 24 - e) % 60);
	}
	else {
		e = 60 * c + d - 60 * a - b;
		printf("%d�ð� %d�� ", e / 60, e % 60);
	}

	return 0;
}