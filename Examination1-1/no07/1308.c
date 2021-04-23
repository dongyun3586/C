#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int h, m, h2, m2;

	printf("현재 시간: ");
	scanf("%d %d", &h, &m);
	printf("알람 시간: ");
	scanf("%d %d", &h2, &m2);

	int h3 = h - h2, m3 = m - m2;
	if (h - h2 < 0) h3 = h3 * -1;
	else if (h - h2 > 0) h3 = h2 + 24 - h;
	else if (m - m2 < 0)m3 = m - m2 + 60;
	h3 = h3 - 1;

	printf("%d시간 %d분 ", h3, m3);

	return 0;
}