#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int a, b, c, d, hour, minute;

	printf("���� �ð�: ");
	scanf("%d %d", &a, &b);
	printf("\n�˶� �ð�: ");		// ���� -1
	scanf("%d %d", &c, &d);

	if (b <= d) {
		minute = d - b;
		hour = (a <= c) ? c - a : c - a + 12;  // hour = (a <= c) ? c - a : c - a + 24;
	}
	else {
		minute = d - b + 60;
		hour = (a <= c) ? c - a - 1 : c - a + 11;  // hour = (a < c) ? c - a - 1 : c - a + 24-1;
	}

	printf("%d�ð� %d��", hour, minute);

	return 0;
}