#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("�˶� �ð�: ");
	scanf("%d %d", &c, &d);

	if (a > c) {
		if (b > d) {
			printf("%d�ð� %d�� ", c+23-a, d+60-b);
		}
		else {
			printf("%d�ð� %d�� ", c + 24 - a, d - b);
		}
	}
	else {
		if (b > d) {
			printf("%d�ð� %d�� ", c -1-a, d + 60 - b);
		}
		else {
			printf("%d�ð� %d�� ", c - a, d - b);
		}
	}
	

	return 0;
}