#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int hh, hm, rh, rm;

	printf("현재 시간: ");
	scanf("%d %d", &hh, &hm);
	printf("알람 시간: ");
	scanf("%d %d", &rh, &rm);

	if(rm>=hm)
		printf("%d시간 %d분 ", (rh-hh+24)%24, rm-hm);
	else
		printf("%d시간 %d분 ", (rh - hh + 23) % 24, rm - hm+60);

	return 0;
}