#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	if (a < c) {
		if (b <= d)
			printf("%d�ð� %d��", c - a, d - b);
		else if (b > d)
			printf("%d�ð� %d��", c - a - 1, b - d);
	}
	else if (a > c) {
		if (b <= d)
			printf("%d�ð� %d��", 24 - a + c + 1, d - b);
		else
			printf("%d�ð� %d��", 24 - a + c, 60 - b + d);
	}
	else {
		printf("0�ð� %d��", d - b);
	}

	return 0;
}