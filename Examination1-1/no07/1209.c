#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a1, b1, a2, b2, num1, num2, finalnum;

	printf("���� �ð�: ");
	scanf("%d %d", &a1, &b1);
	printf("�˶� �ð�: ");
	scanf("%d %d", &a2, &b2);

	num1 = 60 * a1 + b1;
	num2 = 60 * a2 + b2;

	if (num1 > num2)
		num2 += 1440;
	finalnum = num2 - num1;

	printf("%d�ð� %d�� ", finalnum/60, finalnum%60);

	return 0;
}