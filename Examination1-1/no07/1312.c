#include<stdio.h>

/* 알람 시간 출력 */
int main() {
	int h, s, ah, as, x, y;

	printf("현재 시간: ");
	scanf("%d %d", &h, &s);
	printf("\n알람 시간: ");
	scanf("%d %d", &ah, &as);

	if (as < s) {
		y = 60 + as - s;
		if (ah <= h)
			x = 24 + ah - h - 1;
		else
			x = ah - h;
	}
	else {
		y = as - s;
		if (ah < h)
			x = 24 + ah - h;
		else
			x = ah - h;
	}
	printf("%d시간 %d분 ", x, y);

	return 0;
}