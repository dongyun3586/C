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
			printf("%d�ð� %d�� ", c-a,d-b);
		if(d<b)
			printf("%d�ð� %d�� ", c - a-1, 60+d - b);
		if (c < a) {
			if(d>b)
				printf("%d�ð� %d�� ", c - a - 1, d - b);
		}
	}
	

	return 0;
}