#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int n, m, a, b, x, y, z;

	printf("���� �ð�: ");
	scanf("%d %d", &n, &m);
	printf("�˶� �ð�: ");
	scanf("%d %d", &a, &b);

	x = 60 * n + m;
	y = 60 * a + b;
	if (x > y) {
		y = 60 * a + b + 60 * 24;
		z = y - z;
		printf("%d�ð� %d�� ", z/60, z%60);
	}
	if(x==y)
		printf("0�ð� 0��");
	if (x < y) {
		z = y - x;
		printf("%d�ð� %d�� ", z / 60, z % 60);
	}

	return 0;
}