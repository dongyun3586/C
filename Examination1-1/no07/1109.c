#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int hour, min, hour2, min2, h, m;

	printf("현재 시간: ");
	scanf("%d %d", &hour, &min);
	printf("알람 시간: ");
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
	printf("%d시간 %d분 ", h,m);

	return 0;
}