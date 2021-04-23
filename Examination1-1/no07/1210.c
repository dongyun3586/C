#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int H, M, h, m, hour, minute;

	printf("현재 시간: ");
	scanf("%d %d", &H, &M);
	printf("알람 시간: ");
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

	printf("%d시간 %d분 ", hour, minute);

	return 0;
}