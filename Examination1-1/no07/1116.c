#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int hour1, min1, hour2, min2, gap;

	printf("���� �ð�: ");
	scanf("%d %d", &hour1, &min1);
	printf("�˶� �ð�: ");
	scanf("%d %d", &hour2, &min2);

	if (hour1 * 60 + min1 > hour2 * 60 + min2) {
		gap = (hour2 + 24) * 60 + min2 - hour1 * 60 + min1;
		printf("%d�ð� %d�� ", gap/60, gap%60);
	}
	else {
		gap = hour2 * 60 + min2 - hour1 * 60 - min1;
		printf("%d�ð� %d�� ", gap / 60, gap % 60);
	}
	

	return 0;
}