#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int h, m, a, b;

	printf("���� �ð�: ");
	scanf("%d %d", &h, &m);
	printf("�˶� �ð�: ");
	scanf("%d %d", &a, &b);

	if (h > a) {
		if(m>b)
			printf("%d�ð� %d�� ", h-a, m-b);
		else
			printf("%d�ð� %d�� ", h - a-1, m - b+60);
	}
	else {
		if(m>b)
			printf("%d�ð� %d�� ", h - a+24, m - b);
		else
			printf("%d�ð� %d�� ", h - a +23, m - b + 60);
	}
	

	return 0;
}