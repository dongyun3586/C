#include<stdio.h>

/* �˶� �ð� ��� */
int main() {
	int H, M, h, m, hour, minute;

	printf("���� �ð�: ");
	scanf("%d %d", &H, &M);
	printf("�˶� �ð�: ");
	scanf("%d %d", &h, &m);

	if (m - M < 0) {
		minute = m - M + 60;
		hour = h - H - 1;
	}
	else {
		minute = m - M;
		hour = h - H;
	}
	if (hour < 0)
		hour += 24;

	printf("%d�ð� %d�� ", hour, minute);

	return 0;
}