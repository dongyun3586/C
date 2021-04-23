#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int h, m, ah, am, lh, lm;

	printf("현재 시간: ");
	scanf("%d %d", &h, &m);
	printf("알람 시간: ");
	scanf("%d %d", &ah, &am);

	if (am > m) {
		lh = h - 1 - ah;
		lm = m - am + 60;
	}
	else {
		lh = h - ah;
		lm = m - am;
	}
	printf("%d시간 %d분 ", lh, lm);

	return 0;
}