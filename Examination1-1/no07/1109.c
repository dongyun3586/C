#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int hour, min, hour2, min2, h, m;

	printf("���� �ð�: ");
	scanf("%d %d", &hour, &min);
	printf("�˶� �ð�: ");
	scanf("%d %d", &hour2, &min2);

	if (hour > hour2) {
		if (min > min2) {
			h = hour2 + 24 - hour - 1;
			m = min2 + 60 - min;
		}
		else {
			h = hour2 + 24 - hour;
			m = min2 - min;
		}
	}
	else {
		if (min > min2) {
			h = hour2 - hour;
			m = min2 + 60 - min;
		}
		else {
			h = hour2 - hour;
			m = min2 - min;
		}
	}
	printf("%d�ð� %d�� ", h,m);

	return 0;
}