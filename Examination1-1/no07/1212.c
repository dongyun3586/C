#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	if (c < a)
		c += 24;
	if (d < b) {
		c -= 1;
		d += 60;
	}
	printf("%d�ð� %d�� ", c-a, d-b);

	return 0;
}