#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int timen, minn, timea, mina, timer, minr;

	printf("���� �ð�: ");
	scanf("%d %d", &timen, &minn);
	printf("�˶� �ð�: ");
	scanf("%d %d", &timea, &mina);

	timer = (timea + 24 - timen) % 24;
	minr = mina - minn;

	if (minr < 0)
		minr += 60;
	timer -= 1;

	printf("%d�ð� %d�� ", timer, minr);

	return 0;
}