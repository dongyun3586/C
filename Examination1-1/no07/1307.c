#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	if (b > d) {			
		y = 60 + d - b;
		x--;
	}
	else 
		y = d - b;
	if (a > c)
		x = x + 24 + c - a;
	else
		x = x + c - a;
	if (x < 0) x += 24;
	printf("%d�ð� %d�� ", x, y);

	return 0;
}