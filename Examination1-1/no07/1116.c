#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int hour1, min1, hour2, min2, gap;

	printf("현재 시간: ");
	scanf("%d %d", &hour1, &min1);
	printf("알람 시간: ");
	scanf("%d %d", &hour2, &min2);

	if (hour1 * 60 + min1 > hour2 * 60 + min2) {
		gap = (hour2 + 24) * 60 + min2 - hour1 * 60 + min1;
		printf("%d시간 %d분 ", gap/60, gap%60);
	}
	else {
		gap = hour2 * 60 + min2 - hour1 * 60 - min1;
		printf("%d시간 %d분 ", gap / 60, gap % 60);
	}
	

	return 0;
}