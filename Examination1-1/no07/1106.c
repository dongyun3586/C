#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	if(c-a<0&&d-b<0)
		printf("%d�ð� %d�� ", c-a+23, d-b+60);
	if (c - a < 0 && d - b > 0)
		printf("%d�ð� %d�� ", c - a + 24, d - b);
	if (c - a > 0 && d - b < 0)
		printf("%d�ð� %d�� ", c - a -1, d - b + 60);
	if (c - a > 0 && d - b > 0)
		printf("%d�ð� %d�� ", c - a, d - b);

	return 0;
}