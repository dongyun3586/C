#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d, e;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	e = 60 * a - 60 * c + b - d;
	printf("%d �ð� %d �� ", e / 60, e % 60);


	return 0;
}