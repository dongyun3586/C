#include<stdio.h>

/* 알람 시간 출력 1301 곽나영 */
int main() {
	int h, m, H, M;

	printf("현재 시간: ");
	scanf("%d %d", &h, &m);
	printf("알람 시간: ");
	scanf("%d %d", &H, &M);

	int ah = (1440 - ((60 * h + m) - (60 * H + M) + 1440) % 1440) / 60;
	int am = (1440 - ((60 * h + m) - (60 * H + M) + 1440) % 1440) % 60;

	printf("%d시간 %d분 ", ah, am);

	return 0;
}