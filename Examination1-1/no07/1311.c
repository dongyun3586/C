#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d, t;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	if (c >= a) {
		if(d>b)
			printf("%d�ð� %d�� ", c - a, d - b);
		else
			printf("%d�ð� %d�� ", c - a, d - b+60);
	}
	else {
		if (d > b)
			printf("%d�ð� %d�� ", c - a+24, d - b);
		else
			printf("%d�ð� %d�� ", c - a+24, d - b + 60);
	}
	

	return 0;
}