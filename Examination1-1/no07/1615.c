#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int a, b, c, d, hour, minute;

	printf("현재 시간: ");
	scanf("%d %d", &a, &b);
	printf("\n알람 시간: ");		// 감점 -1
	scanf("%d %d", &c, &d);

	if (b <= d) {
		minute = d - b;
		hour = (a <= c) ? c - a : c - a + 12;  // hour = (a <= c) ? c - a : c - a + 24;
	}
	else {
		minute = d - b + 60;
		hour = (a <= c) ? c - a - 1 : c - a + 11;  // hour = (a < c) ? c - a - 1 : c - a + 24-1;
	}

	printf("%d시간 %d분", hour, minute);

	return 0;
}