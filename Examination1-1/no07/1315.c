#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d, h, m;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	h = { (24 + c - a) * 60 + d - b } / 60;
	m = { (24 + c - a) * 60 + d - b } % 60;
	printf("%d�ð� %d�� ", h, m);

	return 0;
}