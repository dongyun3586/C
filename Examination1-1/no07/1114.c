#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	if (c >= a) {
		if(d>=b)
			printf("%d�ð� %d�� ", c-a, d-b);
		else
			printf("%d�ð� %d�� ", c - a-1, 60+d - b);
	}
	else {
		if (d >= b)
			printf("%d�ð� %d�� ", 24+c - a, d - b);
		else
			printf("%d�ð� %d�� ", 23+c - a, 60 + d - b);
	}
	

	return 0;
}